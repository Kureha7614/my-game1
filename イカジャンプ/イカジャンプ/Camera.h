// このヘッダーを同じソース内で何度も読み込まないための指定。
#pragma once
// 関連するデータと処理をまとめるクラス。
class Camera
{
// このクラスの内部から使う変数や型。
private:
	int CameraX = 0;
	float CameraY = 0;
// ほかのクラスから呼び出せる関数など。
public:
	// 時間経過や入力に応じて状態を更新する処理。
	void Update(int playerX, float playerY);
	// カメラのX座標を返す関数。現在のCPPは固定値0を返す仮実装。
	int GetX() const;
	// カメラのY座標を返す関数。現在のCPPは固定値0を返す仮実装。
	float GetY() const;
};

