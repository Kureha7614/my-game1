// このファイルで使うクラスや関数の宣言を読み込む。
#include "BackGround.h"

// 画像などを読み込む処理。voidは戻り値を返さないという意味。
void BackGround::Load()
{
	// ファイルを読み込み、戻り値の管理番号を保存する。失敗時は-1。
	imageHandle = LoadGraph("image/BackGround.png");
}

// 画面に描く処理。移動の計算とは分けている。
void BackGround::Draw()
{
	// 左上と右下の座標で画像の表示範囲を指定する。最後は透過の有無。
	DrawExtendGraph(0, 0, 480, 854, imageHandle, FALSE);
}
