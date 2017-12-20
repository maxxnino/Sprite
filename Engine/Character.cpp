#include "Character.h"

Character::Character(const std::string & filename, int width, int height)
	:
	surf(filename),
	width(width),
	height(height)
{
	for (int i = (int)Sequence::WalkingLeft; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(width,i*height,width,height,4,0.1f);
	}
	for (int i = 0; i < (int)Sequence::Count - (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(0, i*height, width, height, 1, 0.1f);
	}
}

void Character::Draw(Graphics & gfx) const
{
	SpriteEffect::Chroma effect = { Colors::Magenta };
	animations[(int)curAnimation].Draw(pos, surf, gfx, effect);
}

void Character::SetDirection(VecF dir)
{
	if (dir.x < 0.0f)
	{
		curAnimation = Sequence::WalkingLeft;
	}
	else if (dir.x > 0.0f)
	{
		curAnimation = Sequence::WalkingRight;
	}
	else if (dir.y > 0.0f)
	{
		curAnimation = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f)
	{
		curAnimation = Sequence::WalkingUp;
	}
	else if (vel.x < 0.0f)
	{
		curAnimation = Sequence::StandingLeft;
	}
	else if (vel.x > 0.0f)
	{
		curAnimation = Sequence::StandingRight;
	}
	else if (vel.y < 0.0f)
	{
		curAnimation = Sequence::StandingUp;
	}
	else if (vel.x > 0.0f)
	{
		curAnimation = Sequence::StandingDown;
	}
	vel = dir*speed;
}

void Character::Update(float dt)
{
	pos += vel*dt;
	animations[(int)curAnimation].Update(dt);
}
