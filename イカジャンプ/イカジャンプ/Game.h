#pragma once
#include"DxLib.h"
#include"BackGround.h"
#include"Ground.h"
class Game
{
private:
	BackGround background;
	Ground ground;
public:
	void Draw();
};

