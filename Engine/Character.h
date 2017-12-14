#pragma once
#include "Surface.h"
#include "Animation.h"
#include "Graphics.h"
#include "SpriteEffect.h"
#include <string>

class Character
{
public:
	Character(const std::string& filename, int width,int height);
	enum Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
	void Update(float dt);
	void Draw(Graphics& gfx) const;
	void SetDirection(VecF dir);
private:
	Surface surf;
	std::vector<Animation> animations;
	Sequence curAnimation = Sequence::StandingLeft;
	int width;
	int height;
	VecF pos = { 0.0f,0.0f };
	VecF vel = { 0.0f,0.0f };
	static constexpr float speed = 100.0f;
};