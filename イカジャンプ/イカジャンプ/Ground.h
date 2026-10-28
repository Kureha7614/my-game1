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
};

