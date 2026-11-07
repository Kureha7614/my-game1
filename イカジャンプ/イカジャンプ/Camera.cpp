// このファイルで使うクラスや関数の宣言を読み込む。
#include "Camera.h"
#include "Character.h"
#include "DxLib.h"
// 時間経過や入力に応じて状態を更新する処理。
void Camera::Update(int playerX, float playerY)
{
	if (playerY - CameraY < 427)
	{
		CameraY = playerY - 427;// 画面の中心にキャラクターが来るように調整
	}
	
}

// カメラのX座標を返す関数。現在のCPPは固定値0を返す仮実装。
int Camera::GetX() const
{
	// 呼び出し元に0を返す。mainでは正常終了、Cameraの現在の実装では固定の座標0。
	return CameraX;
}

// カメラのY座標を返す関数。現在のCPPは固定値0を返す仮実装。
float Camera::GetY() const
{
	return CameraY;
}
