#include "Menu.h"


Menu::Menu(int nam)
{
	button.emplace_back(new CraftSlot( RectI(850, 50, 970, 170), Colors::Yellow));
	button.emplace_back(new CraftSlot( RectI(970, 50, 1090, 170), Colors::Yellow));
	button.emplace_back(new CraftSlot( RectI(1090, 50, 1210, 170), Colors::Yellow));
	button.emplace_back(new CreateSkill( RectI(890, 210, 1170, 310), Colors::Yellow));
	button.emplace_back(new ElementSlot( RectI(850, 315, 970, 435), Colors::Yellow, TypeElement::Fire ));
	button.emplace_back(new ElementSlot( RectI(970, 315, 1090, 435), Colors::Yellow, TypeElement::Water ));
	button.emplace_back(new ElementSlot( RectI(1090, 315, 1210, 435), Colors::Yellow, TypeElement::Lighting ));
}

void Menu::Draw(Graphics & gfx) const
{
	gfx.DrawSprite(VecI(0, 0), surf, SpriteEffect::Copy());
	for (auto c : button)
	{
		c->Draw(gfx,*this);
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
	for (auto c: button)
	{
		c->Update(mouse, *this,c);
	}
}

const Menu::TypeMenu& Menu::GetState() const
{
	return typeMenu;
}
