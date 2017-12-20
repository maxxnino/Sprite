#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <vector>

class Animation
{
public:
	Animation(int x, int y, int width, int height, int nFrame, float frameTime); 

	template <typename E>
	void Draw(VecI pos, const Surface& surf, Graphics & gfx, E effect) const
	{
		gfx.DrawSprite(pos, frames[curFrame], surf, effect);
	}

	template <typename E>
	void Draw(VecI pos, RectI& clip, const Surface& surf, Graphics & gfx, E effect) const
	{
		gfx.DrawSprite(pos, clip, frames[curFrame], surf, effect);
	}

	void Update(float dt);
private:
	std::vector<RectI> frames;
	int width;
	int height;
	int curFrame = 0;
	int nFrame;
	float frameTime;
	float curFrameTime = 0.0f;
};