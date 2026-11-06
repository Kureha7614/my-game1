// このファイルで使うクラスや関数の宣言を読み込む。
#include "Camera.h"

// 時間経過や入力に応じて状態を更新する処理。
void Camera::Update(int playerX, int playerY)
{

}

// カメラのX座標を返す関数。現在のCPPは固定値0を返す仮実装。
int Camera::GetX() const
{
	// 呼び出し元に0を返す。mainでは正常終了、Cameraの現在の実装では固定の座標0。
	return 0;
}

// カメラのY座標を返す関数。現在のCPPは固定値0を返す仮実装。
int Camera::GetY() const
{
	// 呼び出し元に0を返す。mainでは正常終了、Cameraの現在の実装では固定の座標0。
	return 0;
}
