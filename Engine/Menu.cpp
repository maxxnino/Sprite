#include "Menu.h"


Menu::Menu(Menu::TypeMenu typeMenu)
	:
	typeMenu(typeMenu),
	//Craft Button
	craftButton(CraftButton(RectI(837, 232, 1122, 316), Colors::Blue)),
	skillButton(SkillButton(RectI(928, 468, 1032, 572), Colors::Blue, craftButton))
{
	//Select Ellement
	elementButton.emplace_back(ElementButton( RectI(748, 68, 852, 172), Colors::Blue));
	elementButton.emplace_back(ElementButton( RectI(928, 68, 1032, 172), Colors::Blue));
	elementButton.emplace_back(ElementButton( RectI(1108, 68, 1212, 172), Colors::Blue));
	
	//Element Slot
	int left = 855;
	int top = 405;
	int width = 104;
	int padding = 40;
	int i = 0;
	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
		{
			elementSlot.emplace_back(ElementSlot(RectI(left + (width + padding) * x, top + (width + padding) * y, left + (x + 1)*width + x * padding, top + (y + 1)*width + y * padding),
				Colors::Yellow, static_cast<ElementSlot::ElementType>(i)));
			i++;
		}
	//Load element texture
	skillIcon.emplace_back(Surface("Element\\Fire.bmp"));
	skillIcon.emplace_back(Surface("Element\\Water.bmp"));
	skillIcon.emplace_back(Surface("Element\\Lighting.bmp"));
	skillIcon.emplace_back(Surface("Element\\Earth.bmp"));
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
		craftButton.Draw(gfx);
		break;
	case Menu::MainMenu:
		for (size_t i = 0; i < elementButton.size(); i++)
		{
			elementButton[i].Draw(gfx, skillIcon);
		}
		skillButton.Draw(gfx);
		craftButton.Draw(gfx);
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
	mouseEvent = mouse.Read().GetType();
	switch (typeMenu)
	{
	case Menu::SelectElement:
		for (auto& c : elementSlot)
		{
			if (c.Update(mouse, mouseEvent, dt, buttonSound, clickSound))
			{
				elementButton[indexElementButton].ChangeType(c.GetType());
				ChangeState();
				break;
			}
		}
		break;
	case Menu::MainMenu:
		ScrollMenu.Update(mouse, mouseEvent,dt, buttonSound, clickSound);
		for (auto& e : elementButton)
		{
			if (e.Update(mouse, mouseEvent, dt, buttonSound, clickSound))
			{
				indexElementButton = i;
				ChangeState();
				break;
			}
			i++;
		}
		craftButton.Update(mouse, mouseEvent, dt, elementButton, buttonSound, CraftSound);
		skillButton.Update(mouse, mouseEvent,dt, buttonSound, CraftSound);
		break;
	default:
		break;
	}
}
