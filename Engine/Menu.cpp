#include "Menu.h"


Menu::Menu(int nam)
{
	mainMenu.emplace_back(MenuVariable{ RectI(850, 50, 970, 170), Colors::Yellow, TypeButton::ElementButton });
	mainMenu.emplace_back(MenuVariable{ RectI(970, 50, 1090, 170), Colors::Yellow, TypeButton::ElementButton });
	mainMenu.emplace_back(MenuVariable{ RectI(1090, 50, 1210, 170), Colors::Yellow, TypeButton::ElementButton });
	mainMenu.emplace_back(MenuVariable{ RectI(890, 210, 1170, 310), Colors::Yellow, TypeButton::CraftButton });
	ElementMenu.emplace_back(MenuVariable{ RectI(850, 315, 970, 435), Colors::Yellow, TypeButton::ElementButton,TypeSkill::Fire });
	ElementMenu.emplace_back(MenuVariable{ RectI(970, 315, 1090, 435), Colors::Yellow, TypeButton::ElementButton,TypeSkill::Water });
	ElementMenu.emplace_back(MenuVariable{ RectI(1090, 315, 1210, 435), Colors::Yellow, TypeButton::ElementButton,TypeSkill::Lighting });
}

void Menu::Draw(Graphics & gfx) const
{
	gfx.DrawSprite(VecI(0, 0), surf, SpriteEffect::Copy());
	switch (typeMenu)
	{
	case TypeMenu::SelectElement:
		for (int i = 0; i < ElementMenu.size(); i++)
		{
			Color c;
			switch (ElementMenu[i].TypeSkill)
			{
			case TypeSkill::Fire:
				c = Colors::Red;
				break;
			case TypeSkill::Water:
				c = Colors::Blue;
				break;
			case TypeSkill::Lighting:
				c = Colors::White;
				break;
			default:
				break;
			}
			gfx.DrawRectAndColor(ElementMenu[i].rect, 10, ElementMenu[i].menuColor,c);
		}
		for (int i = 0; i < mainMenu.size(); i++)
		{
			Color c;
			switch (mainMenu[i].typeButton)
			{
			case TypeButton::CraftButton:
				gfx.DrawRect(mainMenu[i].rect, 10, mainMenu[i].menuColor);
				break;
			case TypeButton::ElementButton:
				switch (mainMenu[i].TypeSkill)
				{
				case TypeSkill::Fire:
					c = Colors::Red;
					break;
				case TypeSkill::Water:
					c = Colors::Blue;
					break;
				case TypeSkill::Lighting:
					c = Colors::White;
					break;
				case TypeSkill::None:
					c = Colors::Black;
					break;
				default:
					break;
				}
				gfx.DrawRectAndColor(mainMenu[i].rect, 10, mainMenu[i].menuColor, c);
				break;
			default:
				break;
			}
		}
		break;
	case TypeMenu::MainMenu:
		for (int i = 0; i < mainMenu.size(); i++)
		{
			Color c;
			switch (mainMenu[i].typeButton)
			{
			case TypeButton::CraftButton:
				gfx.DrawRect(mainMenu[i].rect, 10, mainMenu[i].menuColor);
				break;
			case TypeButton::ElementButton:
				switch (mainMenu[i].TypeSkill)
				{
				case TypeSkill::Fire:
					c = Colors::Red;
					break;
				case TypeSkill::Water:
					c = Colors::Blue;
					break;
				case TypeSkill::Lighting:
					c = Colors::White;
					break;
				case TypeSkill::None:
					c = Colors::Black;
					break;
				default:
					break;
				}
				gfx.DrawRectAndColor(mainMenu[i].rect, 10, mainMenu[i].menuColor, c);
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}

}

void Menu::ButtonClick(MenuVariable& menu)
{
	if (typeMenu == TypeMenu::SelectElement)
	{
		typeMenu = TypeMenu::MainMenu;
	}
	else if (typeMenu == TypeMenu::MainMenu)
	{
		switch (menu.typeButton)
		{
		case Menu::TypeButton::ElementButton:
			typeMenu = Menu::SelectElement;
			break;
		case Menu::TypeButton::CraftButton:
			menu.menuColor = Colors::Blue;
			break;
		default:
			break;
		}
	}

}

void Menu::Update(Mouse& mouse, float dt)
{
	switch (typeMenu)
	{
	case Menu::TypeMenu::SelectElement:
		for (int i = 0; i < ElementMenu.size(); i++)
		{
			if (ElementMenu[i].rect.isContaint(mouse.GetPos()))
			{
				ElementMenu[i].menuColor = Colors::Green;
				while (!mouse.IsEmpty())
				{
					const Mouse::Event e = mouse.Read();
					if (e.GetType() == Mouse::Event::Type::LPress)
					{
						ButtonClick(ElementMenu[i]);
						switch (i)
						{
						case 0:
							subbuttonClick = TypeSkill::Fire;
							break;
						case 1:
							subbuttonClick = TypeSkill::Water;
							break;
						case 2:
							subbuttonClick = TypeSkill::Lighting;
							break;
						default:
							break;
						}
						continue;
					}
				}
			}
			else
			{
				ElementMenu[i].menuColor = Colors::Yellow;
			}
		}
		break;
	case Menu::TypeMenu::MainMenu:
		for (int i = 0; i < mainMenu.size(); i++)
		{
			if (mainMenu[i].rect.isContaint(mouse.GetPos()))
			{
				mainMenu[i].menuColor = Colors::Green;
				while (!mouse.IsEmpty())
				{
					const Mouse::Event e = mouse.Read();
					if (e.GetType() == Mouse::Event::Type::LPress)
					{
						ButtonClick(mainMenu[i]);
						buttonClick = i;
						continue;
					}
				}
			}
			else
			{
				mainMenu[i].menuColor = Colors::Yellow;
			}
		}
		break;
	default:
		break;
	}
	mainMenu[buttonClick].TypeSkill = subbuttonClick;
}
