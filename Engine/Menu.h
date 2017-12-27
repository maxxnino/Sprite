#pragma once
#include "Surface.h"
#include "Graphics.h"
#include "SpriteEffect.h"
#include "Mouse.h"
#include "Button.h"
#include "Sound.h"
#include <vector>
#include "ScrollingMenu.h"

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
	std::vector<ElementSlot> elementSlot;
	std::vector<ElementButton> elementButton;
	std::vector<CraftButton> craftButton;
	std::vector<Surface> skillIcon;
	//Background Menu
	Surface surf = ("Skill_menu.bmp");
	Sound buttonSound = { L"Sounds\\Slither0.wav" };
	Sound clickSound = { L"Sounds\\Eat.wav" };
	Sound CraftSound = { L"Sounds\\arkpad.wav" };
	ScrollingMenu ScrollMenu = {RectI(100,100,400,600)};
	TypeMenu typeMenu = TypeMenu::MainMenu;
	//Store index Element when choose element
	int indexElementButton;
};