#include"Animation.h"

void Animation::Update()
{
	frameTimer++;
	if (frameInterval <= frameTimer)
	{
		frameTimer = 0;
		currentFrame++;
		if (frameCount <= currentFrame)
		{
			currentFrame = 0;
		}
	}
}

void Animation::Reset()
{
	currentFrame = 0;
	frameTimer = 0;
}

int Animation::GetCurrentFrame() const
{
	return currentFrame;
}

void Animation::SetFrameCount(int count)
{
	frameCount = count;
	Reset();
}
