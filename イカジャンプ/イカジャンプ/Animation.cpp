// このファイルで使うクラスや関数の宣言を読み込む。
#include"Animation.h"

// 時間経過や入力に応じて状態を更新する処理。
void Animation::Update()
{
	// ++ は1を足す。更新を何回行ったか数える。
	frameTimer++;
	// if は条件が成り立つときだけ中を実行する。指定した回数を待ったか確認。
	if (frameInterval <= frameTimer)
	{
		frameTimer = 0;
		// 表示するコマ番号を1つ進める（番号は0から始まる）。
		currentFrame++;
		// 最後のコマを超えたら、最初の0番へ戻す。
		if (frameCount <= currentFrame)
		{
			currentFrame = 0;
		}
	}
}

// コマ番号とタイマーを戻し、最初から再生できるようにする。
void Animation::Reset()
{
	currentFrame = 0;
	frameTimer = 0;
}

// 現在のコマ番号をintで返す。末尾のconstはオブジェクトの状態を変えない指定。
int Animation::GetCurrentFrame() const
{
	// return は値を呼び出し元へ返す。ここでは現在のコマ番号。
	return currentFrame;
}

// 引数で受け取ったコマ数を設定する。1以上の数を渡して使う。
void Animation::SetFrameCount(int count)
{
	// = は代入。引数countで受け取った数を、クラスの変数に保存する。
	frameCount = count;
	// 同じクラスのReset関数を呼び、再生位置を最初に戻す。
	Reset();
}

// 次のコマまで待つ更新回数を、引数で受け取って設定する。
void Animation::SetFrameInterval(int interval)
{
    // コマをリセットせず、切り替え間隔だけを変更する
    if (interval < 1) interval = 1;
    // 引数intervalで受け取った更新間隔を保存する。
    frameInterval = interval;
}