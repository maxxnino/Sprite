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
	Menu(Menu::TypeMenu typeMenu = MainMenu);
	void Draw(Graphics& gfx) const;
	void ChangeState();
	void Update(Mouse& mouse, float dt);
private:
	// Button Container
	std::vector<ElementButton> elementButton;
	std::vector<CraftButton> craftButton;
	std::vector<ElementButton> elementSlot;
	//Background Menu
	Surface surf = ("Skill_menu.bmp");
	TypeMenu typeMenu = TypeMenu::MainMenu;
	//Store index Element when choose element
	int indexElementButton;
};