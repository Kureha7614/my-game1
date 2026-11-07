// このファイルで使うクラスや関数の宣言を読み込む。
#include "Character.h"
// このファイルで使うクラスや関数の宣言を読み込む。
#include "DxLib.h"

// 画像などを読み込む処理。voidは戻り値を返さないという意味。
void Character::Load()
{
    // ファイルを読み込み、戻り値の管理番号を保存する。失敗時は-1。
    imageHandle = LoadGraph("image/spreadsheet.png");
    animation.SetFrameCount(8);  // 例: 8コマのアニメーション
}



// 画面に描く処理。移動の計算とは分けている。
void Character::Draw(float cameraY)
{
    // == は同じ値かの比較。画像がなければ、この関数をここで終了する。
    if (imageHandle == -1) return;

    // ドットでオブジェクトの関数を呼ぶ。戻り値を保存し、constで変更しない変数にする。
    const int currentFrame = animation.GetCurrentFrame();
    // 元画像に合わせた横の間隔。余白も含めて1コマを切り出す
    int sourceX = 12 + currentFrame * 178;
    // 元画像の切り出し開始Y座標。画面上のplayerYとは別の座標。
    int sourceY = 20;
    // 元画像から切り出す高さ。表示するときの高さとは別。
    int sourceHeight = 180;
    // ためている場合の絵を、走りやジャンプより先に選ぶ。
    if (isCharging == true)
    {
        sourceX = 0; // ためポーズとして、画像の左端から切り出す
        sourceY = 545; // 4段目：ジャンプのポーズ
    }
    // else ifは前の条件が成り立たなかったときに調べる次の条件。
    else if(state == State::Run)
    {
        sourceY = 365; // 左右とも3段目の走りを使う
    }
    // || は「または」。ジャンプ中か落下中なら同じポーズを選ぶ。
    else if (state == State::Jump || state == State::Fall)
    {
		sourceX = 12 + 6 * 178; // ジャンプのポーズは7コマ目
        sourceY = 545; // 4段目：ジャンプのポーズ
        sourceHeight = 185;
    }

    // static_castで型を変換する。描画に渡すため、小数の位置を整数にする。
    const int drawY = static_cast<int>(playerY - cameraY);
	if (facingLeft)
	{
		// 左向きに描画する場合は、画像を反転させる
		DrawRectExtendGraph(playerX + 80, drawY, playerX, drawY + 90,
			sourceX, sourceY, 178, sourceHeight, imageHandle, TRUE);
	}
	else
	{
		// 右向きに描画する場合は、通常通り描画する
		DrawRectExtendGraph(playerX, drawY, playerX + 80, drawY + 90,
			sourceX, sourceY, 178, sourceHeight, imageHandle, TRUE);
	}
	//ゲームオーバー判定
    if(playerY > cameraY + 854)
    {
        IsGameOver = true;
    }
    
}

// 時間経過や入力に応じて状態を更新する処理。
void Character::Update()
{


    // 位置を動かす前に、現在のY座標を保存しておく。
    previousY = playerY;
    // 移動前のX座標。移動後と比べて、動いたかと向きを判断する。
    const int previousX = playerX;
	// boolは== trueを省略できる。今は移動判定後にため状態が更新されるので、押し始めの1回は移動し得る。
	if (isCharging)
	{
		// ため中は移動できない
		movingHorizontally = false;
	}
	else
	{
		// 左キーかAならXを5減らす。-= は引き算した結果を保存する。
		if (CheckHitKey(KEY_INPUT_A) || (CheckHitKey(KEY_INPUT_LEFT))) playerX -= 5;
		// 右キーかDならXを5増やす。
		if (CheckHitKey(KEY_INPUT_D) || (CheckHitKey(KEY_INPUT_RIGHT))) playerX += 5;
		// != は「同じではない」。座標が変わったかをtrue/falseで保存する。
		movingHorizontally = playerX != previousX;
		if (playerX < previousX) facingLeft = true;
		else if (playerX > previousX) facingLeft = false;
	}
    // != は「同じではない」。座標が変わったかをtrue/falseで保存する。
    movingHorizontally = playerX != previousX;
    if (playerX < previousX) facingLeft = true;
    else if (playerX > previousX) facingLeft = false;

    // スペースか上キーの、どちらかが押されているか調べる。
    const bool jumpPressed = CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP);
    // && は「かつ」。地面にいて、さらにジャンプキーが押されているとき。
    if (onGround && jumpPressed)
    {
        // ! は条件の反転。まだため始めていないときだけ、開始時刻を保存する。
        if (!isCharging)
        {
            // 現在の時刻カウントをミリ秒で取得する。
            PushStartTime = GetNowCount();
            isCharging = true;
        }
        // 現在時刻から開始時刻を引いて、ためていた時間を求める。
        PushCount = GetNowCount() - PushStartTime;
        // 3000ミリ秒は3秒。それ以上ためても最大値に止める。
        if (PushCount > 3000) PushCount = 3000;
    }
    else if (isCharging)
    {
        // 地面にいてキーを離したとき、ためた時間からジャンプ速度を決める。
        if (onGround && !jumpPressed)
        {
            // 現在時刻から開始時刻を引いて、ためていた時間を求める。
            PushCount = GetNowCount() - PushStartTime;
            // 3000ミリ秒は3秒。それ以上ためても最大値に止める。
            if (PushCount > 3000) PushCount = 3000;
            // 短押しは -9、3秒ためると -15.5
            velocityY = -(9.0f + 6.5f * (PushCount / 3000.0f));
            // 地面にいる状態を解除する。着地判定では、このあと条件が合えばtrueに戻す。
            onGround = false;
        }
        isCharging = false;
        PushCount = 0;
    }

    // 1秒に60回更新する。画面の下方向がプラス
    // += は加算して保存。下向きの重力で、縦速度を少しずつ増やす。
    velocityY += 0.5f;
    // 現在の位置に速度を足して、今回の位置へ進める。
    playerY += velocityY;
    // 条件 ? 真の値 : 偽の値。地上なら待機か走り、空中なら上昇か落下を選ぶ。
    state = onGround ? (playerX == previousX ? State::Idle : State::Run)
                     : (velocityY < 0.0f ? State::Jump : State::Fall);
}

// 引数left・right・topは足場の左端・右端・上端。上から着地するか調べる。
void Character::CheckLanding(float left, float right, float top)
{
    // 胴体・足の幅で横の重なりを判定する
    const bool overlaps = playerX + 55 > left && playerX + 25 < right;
    // 地面にいる状態を解除する。着地判定では、このあと条件が合えばtrueに戻す。
    onGround = false;
    // 上昇中や、足場の下からの接触は通り抜ける
    if (velocityY >= 0.0f && overlaps &&
        previousY + FootOffset <= top && playerY + FootOffset >= top)
    {
        // 足元が足場の上端と一致するように、キャラのY座標を調整する。
        playerY = top - FootOffset;
        // 着地したので縦の動きを止める。
        velocityY = 0.0f;
        onGround = true;
        state = movingHorizontally ? State::Run : State::Idle;
    }
    if (!onGround)
    {
        isCharging = false;
        state = velocityY < 0.0f ? State::Jump : State::Fall;
    }
}
int Character::GetX() const
{
	return playerX;
}

float Character::GetY() const
{
    return playerY;
}

bool Character::GetIsGameOver() const
{
    return IsGameOver;
}
  

// 着地判定で状態が確定してから、表示するアニメーションを進める
void Character::UpdateAnimation()
{
    // 動作が切り替わったときだけアニメーションを最初に戻す。
    if (state != animationState)
    {
        animation.Reset();
        animationState = state;
    }
    if (state == State::Run)
    {
        animation.SetFrameInterval(6); // 走りは0.1秒ごと
        animation.Update();
    }
    else if (state == State::Idle)
    {
        animation.SetFrameInterval(32); // 待機は今までの速さ
        animation.Update();
    }
    // ジャンプ・落下中は、Drawで指定した1枚を表示する
}