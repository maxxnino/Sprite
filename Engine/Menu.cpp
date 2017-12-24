#include "Menu.h"


Menu::Menu(Menu::TypeMenu typeMenu)
	:
	typeMenu(typeMenu)
{
	//Select Ellement
	elementButton.emplace_back(ElementButton( RectI(850, 50, 970, 170), Colors::Yellow, ElementButton::ElementType::None));
	elementButton.emplace_back(ElementButton( RectI(970, 50, 1090, 170), Colors::Yellow, ElementButton::ElementType::None));
	elementButton.emplace_back(ElementButton( RectI(1090, 50, 1210, 170), Colors::Yellow, ElementButton::ElementType::None));
	//Craft Button
	craftButton.emplace_back(CraftButton( RectI(890, 210, 1170, 310), Colors::Yellow));
	//Eleemt Slot
	elementSlot.emplace_back(ElementButton( RectI(850, 315, 970, 435), Colors::Yellow, ElementButton::ElementType::Fire));
	elementSlot.emplace_back(ElementButton( RectI(970, 315, 1090, 435), Colors::Yellow, ElementButton::ElementType::Water));
	elementSlot.emplace_back(ElementButton( RectI(1090, 315, 1210, 435), Colors::Yellow, ElementButton::ElementType::Earth));
}

void Menu::Draw(Graphics & gfx) const
{
	gfx.DrawSprite(VecI(0, 0), surf, SpriteEffect::Copy());
	switch (typeMenu)
	{
	case Menu::SelectElement:
		for (auto& c : elementSlot)
		{
			c.Draw(gfx);
		}
		craftButton[0].Draw(gfx);
		break;
	case Menu::MainMenu:
		for (auto& c : elementButton)
		{
			c.Draw(gfx);
		}
		craftButton[0].Draw(gfx);
		break;
	default:
		break;
	}
}

void Menu::ChangeState()
{
	if (typeMenu == TypeMenu::SelectElement)
	{
		typeMenu = TypeMenu::MainMenu;
	}
	else
	{
		typeMenu = TypeMenu::SelectElement;
	}	
}

void Menu::Update(Mouse& mouse, float dt)
{
	int i = 0;
	switch (typeMenu)
	{
	case Menu::SelectElement:
		for (auto& c : elementSlot)
		{
			if (c.Update(mouse, dt))
			{
				elementButton[indexElementButton].ChangeType(c.GetType());
				ChangeState();
				break;
			}
		}
		break;
	case Menu::MainMenu:
		for (auto& c : elementButton)
		{
			for (auto& c : craftButton)
			{
				c.Update(mouse, dt);
			}
			if (c.Update(mouse, dt))
			{
				indexElementButton = i;
				ChangeState();
				break;
			}
			i++;
		}
		break;
	default:
		break;
	}
}
