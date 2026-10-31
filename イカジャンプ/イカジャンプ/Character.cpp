#include "Character.h"
#include "DxLib.h"

void Character::Load()
{
    imageHandle = LoadGraph("image/spreadsheet.png");
}

void Character::Draw()
{
    if (imageHandle == -1) return;
    const int drawY = static_cast<int>(playerY);
    DrawRectExtendGraph(playerX, drawY, playerX + 80, drawY + 90,
        20, 20, 160, 180, imageHandle, TRUE);
}

void Character::Update()
{
    previousY = playerY;
    const int previousX = playerX;
    if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT)) playerX -= 5;
    if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)) playerX += 5;

    const bool jumpPressed = CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP);
    if (onGround && jumpPressed)
    {
        if (!isCharging)
        {
            PushStartTime = GetNowCount();
            isCharging = true;
        }
        PushCount = GetNowCount() - PushStartTime;
        if (PushCount > 3000) PushCount = 3000;
    }
    else if (isCharging)
    {
        if (onGround && !jumpPressed)
        {
            PushCount = GetNowCount() - PushStartTime;
            if (PushCount > 3000) PushCount = 3000;
            // 短押しは -9、3秒ためると -15.5
            velocityY = -(9.0f + 6.5f * (PushCount / 3000.0f));
            onGround = false;
        }
        isCharging = false;
        PushCount = 0;
    }

    // 1秒に60回更新する。画面の下方向がプラス
    velocityY += 0.5f;
    playerY += velocityY;
    state = onGround ? (playerX == previousX ? State::Idle : State::Run)
                     : (velocityY < 0.0f ? State::Jump : State::Fall);
}

void Character::CheckLanding(float left, float right, float top)
{
    // 胴体・足の幅で横の重なりを判定する
    const bool overlaps = playerX + 55 > left && playerX + 25 < right;
    onGround = false;
    // 上昇中や、足場の下からの接触は通り抜ける
    if (velocityY >= 0.0f && overlaps &&
        previousY + FootOffset <= top && playerY + FootOffset >= top)
    {
        playerY = top - FootOffset;
        velocityY = 0.0f;
        onGround = true;
        if (state == State::Jump || state == State::Fall) state = State::Idle;
    }
    if (!onGround)
    {
        isCharging = false;
        state = velocityY < 0.0f ? State::Jump : State::Fall;
    }
}