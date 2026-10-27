#include "Ground.h"

void Ground::Draw()
{
	DrawBox(x, y, x + width, y + height, GetColor(239, 160, 203), TRUE);
}
