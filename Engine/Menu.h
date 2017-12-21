#pragma once
#include "Surface.h"
#include "Graphics.h"
#include "SpriteEffect.h"
#include "Mouse.h"
#include <vector>

class Menu
{
	enum TypeMenu
	{
		SkillElement,
		CraftButton,
		SkillSlot,
		Count
	};
	struct RectAndColor
	{
		RectI rect;
		Color menuColor;
		TypeMenu type;
	};
public:
	void Draw(Graphics& gfx) const;
	void ButtonClick(RectAndColor& rect);
	void Update(const Mouse& mouse, float dt);
private:
	std::vector<RectAndColor> menu = { {RectI(850, 50,970,170),Colors::Yellow,SkillElement },
										{RectI(970, 50, 1090, 170),Colors::Yellow,SkillElement },
										{RectI(1090, 50, 1210, 170), Colors::Yellow,SkillElement },
										{RectI(890, 210, 1170, 310), Colors::Yellow ,CraftButton } };
	Surface surf = ("Skill_menu.bmp");
	bool isCoolDown = false;
	float CoolDownTime = 0.5f;
	float curCoolDown = 0.0f;
};