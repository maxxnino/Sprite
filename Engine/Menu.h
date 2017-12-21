#pragma once
#include "Surface.h"
#include "Graphics.h"
#include "SpriteEffect.h"
#include "Mouse.h"
#include "Button.h"
#include <vector>

class Menu
{
public:
	enum TypeMenu
	{
		SelectElement,
		MainMenu
	};
public:
	Menu(int nam);
	void Draw(Graphics& gfx) const;
	void ChangeState();
	void Update(Mouse& mouse, float dt);
	const TypeMenu& GetState() const;
private:
	std::vector<Button*> button;
	Surface surf = ("Skill_menu.bmp");
	TypeMenu typeMenu = TypeMenu::MainMenu;
};