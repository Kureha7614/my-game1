#pragma once
#include"DxLib.h"
class Ground
{
private:
	int width = 200;
	int height = 100;
	int x = 140;
	int y = 750;
	int imageHandle = -1;
public:
	void Load();
	void Draw();
	float GetLeft() const { return static_cast<float>(x); }
	float GetRight() const { return static_cast<float>(x + width); }
	// 画像上端から約28%は透明な余白
	float GetTop() const { return y + height * 0.28f; }
};

