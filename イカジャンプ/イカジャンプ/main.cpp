#include"Dxlib.h"
#include"Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(480, 854, 32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//GameÇåƒÇ—èoÇ∑
	Game game;
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		//ï`âÊ
		game.Draw();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}