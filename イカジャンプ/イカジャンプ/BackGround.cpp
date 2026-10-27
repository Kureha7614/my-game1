#include "BackGround.h"

void BackGround::Load()
{
	imageHandle = LoadGraph("image/BackGround.png");
}

void BackGround::Draw()
{
	DrawExtendGraph(0, 0, 480, 854, imageHandle, FALSE);
}
