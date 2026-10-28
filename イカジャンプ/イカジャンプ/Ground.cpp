#include "Ground.h"

void Ground::Load()
{
	imageHandle = LoadGraph("image/Ground.png");
}

void Ground::Draw()
{
	DrawExtendGraph(x, y, x + width, y + height,imageHandle, TRUE);

}
