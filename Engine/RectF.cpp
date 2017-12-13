#include "RectF.h"

RectF::RectF(float left, float top, float right, float bottom)
	:
	left(left),
	top(top),
	right(right),
	bottom(bottom)
{
}

RectF::RectF(const Vec2 & topleft, const Vec2 & bottomright)
	:
	RectF(topleft.x, topleft.y, bottomright.x, bottomright.y)
{
}

RectF::RectF(const Vec2 & topleft, float width, float height)
	:
	RectF(topleft, topleft + Vec2(width, height))
{
}

RectF RectF::GetRectCenter(const Vec2 & center, float halfwidth, float halfheight)
{
	Vec2 half = Vec2(halfwidth, halfheight);
	return RectF(center - half, center + half);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left+ right)/2.0f, (top + bottom) / 2.0f);
}

bool RectF::isOverLap(const RectF & rect) const
{
	return left < rect.right
		&& right > rect.left
		&& bottom > rect.top
		&& top < rect.bottom;
}
