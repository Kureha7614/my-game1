#include"Dxlib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(800, 600, 32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	DxLib_End();
	return 0;
}