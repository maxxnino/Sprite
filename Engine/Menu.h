#pragma once
#include "Surface.h"
#include "Graphics.h"
#include "SpriteEffect.h"
#include "Mouse.h"
#include <vector>

class Menu
{
public:
	enum TypeButton
	{
		CraftButton,
		ElementButton
	};
	enum TypeMenu
	{
		SelectElement,
		MainMenu
	};
	enum TypeSkill
	{
		Fire,
		Water,
		Lighting,
		None
	};
	struct MenuVariable
	{
		RectI rect;
		Color menuColor;
		TypeButton typeButton;
		TypeSkill TypeSkill = TypeSkill::None;
	};
public:
	Menu(int nam);
	void Draw(Graphics& gfx) const;
	void ButtonClick(MenuVariable& rect);
	void Update(Mouse& mouse, float dt);
private:
	std::vector<MenuVariable> mainMenu;
	std::vector<MenuVariable> ElementMenu;
	Surface surf = ("Skill_menu.bmp");
	int buttonClick = 0;
	TypeSkill subbuttonClick = None;
	TypeMenu typeMenu = TypeMenu::MainMenu;
};