#include "Animation.h"
#include <cassert>

Animation::Animation(int x, int y, int width, int height, int nFrame, float frameTime)
	:
	width(width),
	height(height),
	nFrame(nFrame),
	frameTime(frameTime)
{
	for (int i = 0; i < nFrame; i++)
	{
		frames.emplace_back(RectI(VecI(x + i*width, y), width, height));
	}
}

void Animation::Update(float dt)
{
	assert(curFrame >= 0 && curFrame < nFrame);
	curFrameTime += dt;
	while (curFrameTime > frameTime)
	{
		curFrame++;
		curFrameTime -= frameTime;
	}
	if (curFrame >= nFrame)
	{
		curFrame = 0;
	}
}
