#include "ScrollingMenu.h"

ScrollingMenu::ScrollingMenu(RectI rectMenu)
	:
	rectMenu(rectMenu)
{
	VecI aposButton = { rectMenu.left + buttonPadding,rectMenu.top + buttonPadding };
	for (int i = 0; i < nButton; i++)
	{
		buttons.emplace_back(RectI(aposButton.x, aposButton.y + i * (buttonDismention + buttonPadding), aposButton.x + buttonDismention,
			aposButton.y + (i + 1) * buttonDismention + i * buttonPadding), Colors::Blue);
	}
}

void ScrollingMenu::Draw(Graphics & gfx) const
{
	for (int i = 0; i < nButton; i++)
	{
		buttons[i].Draw(rectMenu, gfx);
	}
}

void ScrollingMenu::Update(Mouse & mouse, float dt, Sound & sound, Sound & clickSound)
{
	if (rectMenu.isContaint(mouse.GetPos()))
	{
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();
			if (e.GetType() == Mouse::Event::Type::WheelUp)
			{
				moveVertical = -(int)(speedScrolling * dt);
			}
			else if (e.GetType() == Mouse::Event::Type::WheelDown)
			{
				moveVertical = (int)(speedScrolling * dt);
			}
		}
		for (auto& c : buttons)
		{
			c.MoveButtonVerical(moveVertical);
			c.Update(mouse, dt, sound, clickSound);
		}
	}
}
