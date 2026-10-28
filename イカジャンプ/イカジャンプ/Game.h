#pragma once
#include"DxLib.h"
#include"BackGround.h"
#include"Ground.h"
#include"Character.h"
class Game
{
private:
	BackGround background;
	Ground ground;
	Character character;
public:
	void Load();
	void Draw();
	void Update();
};

