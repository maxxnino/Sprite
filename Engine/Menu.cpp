#include "Menu.h"


void Menu::Draw(Graphics & gfx) const
{
	gfx.DrawSprite(VecI(0, 0), surf, SpriteEffect::Copy());
	for (int i = 0; i < menu.size(); i++)
	{
		gfx.DrawRect(menu[i].rect, 10, menu[i].menuColor);
	}
}

void Menu::ButtonClick(RectAndColor& menu)
{
	switch (menu.type)
	{
	case Menu::SkillElement:
		break;
	case Menu::CraftButton:
		menu.menuColor = Colors::Blue;
		break;
	case Menu::SkillSlot:
		break;
	case Menu::Count:
		break;
	default:
		break;
	}
}

void Menu::Update(const Mouse& mouse, float dt)
{
	if (isCoolDown)
	{
		curCoolDown += dt;
		if (curCoolDown >= CoolDownTime)
		{
			curCoolDown = 0.0f;
			isCoolDown = false;
		}
	}
	else
	{
		for (int i = 0; i < menu.size(); i++)
		{
			if (menu[i].rect.isContaint(mouse.GetPos()))
			{
				menu[i].menuColor = Colors::Green;
				if (mouse.LeftIsPressed())
				{
					ButtonClick(menu[i]);
					isCoolDown = true;
				}
				continue;
			}
			else
			{
				menu[i].menuColor = Colors::Yellow;
			}
		}
	}
}
