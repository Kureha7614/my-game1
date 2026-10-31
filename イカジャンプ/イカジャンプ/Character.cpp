#include "Character.h"
#include "DxLib.h"

void Character::Load()
{
    // スプライトシート全体を読み込む
    imageHandle = LoadGraph("image/spreadsheet.png");
}

void Character::Draw()
{
    if (imageHandle == -1)
    {
        return;
    }

    // 左上の立ち姿を1コマだけ描画する
    DrawRectExtendGraph(
        playerX, playerY,           // 画面上の左上
        playerX + 80, playerY + 90, // 画面上の右下（幅80・高さ90）
        20, 20,                    // 元画像の切り出し位置
        160, 180,                  // 元画像の切り出しサイズ
        imageHandle, TRUE
    );

}

void Character::Update()
{
    if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT))
    {
        playerX -= 5;
    }
    if (CheckHitKey(KEY_INPUT_D) || CheckHitKey( KEY_INPUT_RIGHT))
    {
        playerX += 5;
    }
    if (CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP))
    {

        PushStartTime = GetNowCount();
        PushCount = GetNowCount() - PushStartTime;
        if(PushCount < )
    }
}
