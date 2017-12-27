#include "Menu.h"


Menu::Menu(Menu::TypeMenu typeMenu)
	:
	typeMenu(typeMenu)
{
	//Select Ellement
	elementButton.emplace_back(ElementButton( RectI(748, 68, 852, 172), Colors::Blue));
	elementButton.emplace_back(ElementButton( RectI(928, 68, 1032, 172), Colors::Blue));
	elementButton.emplace_back(ElementButton( RectI(1108, 68, 1212, 172), Colors::Blue));
	//Craft Button
	craftButton.emplace_back(CraftButton( RectI(837, 232, 1122, 316), Colors::Blue));
	//Element Slot
	int left = 805;
	int top = 405;
	int width = 104;
	int padding = 20;
	int i = 0;
	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 3; x++)
		{
			elementSlot.emplace_back(ElementSlot(RectI(left + (width + padding) * x, top + (width + padding) * y, left + (x + 1)*width + x * padding, top + (y + 1)*width + y * padding),
				Colors::Yellow, static_cast<ElementSlot::ElementType>(i)));
			i++;
		}
	//Load element texture
	skillIcon.emplace_back(Surface("Element\\Fire.bmp"));
	skillIcon.emplace_back(Surface("Element\\Water.bmp"));
	skillIcon.emplace_back(Surface("Element\\Earth.bmp"));
	skillIcon.emplace_back(Surface("Element\\Lighting.bmp"));
	skillIcon.emplace_back(Surface("Element\\Nature.bmp"));
	skillIcon.emplace_back(Surface("Element\\Wind.bmp"));
}

void Menu::Draw(Graphics & gfx) const
{
	gfx.DrawSprite(VecI(0, 0), surf, SpriteEffect::Copy());
	ScrollMenu.Draw(gfx);
	switch (typeMenu)
	{
	case Menu::SelectElement:
		for (size_t i = 0; i < elementSlot.size(); i++)
		{
			elementSlot[i].Draw(gfx,skillIcon[i]);
		}
		for (size_t i = 0; i < elementButton.size(); i++)
		{
			elementButton[i].Draw(gfx, skillIcon);
		}
		craftButton[0].Draw(gfx);
		break;
	case Menu::MainMenu:
		for (size_t i = 0; i < elementButton.size(); i++)
		{
			elementButton[i].Draw(gfx, skillIcon);
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
			if (c.Update(mouse, dt, buttonSound, clickSound))
			{
				elementButton[indexElementButton].ChangeType(c.GetType());
				ChangeState();
				break;
			}
		}
		break;
	case Menu::MainMenu:
		ScrollMenu.Update(mouse, dt, buttonSound, CraftSound);
		for (auto& e : elementButton)
		{
			for (auto& c : craftButton)
			{
				c.Update(mouse, dt, buttonSound, CraftSound);
			}
			if (e.Update(mouse, dt, buttonSound, clickSound))
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
