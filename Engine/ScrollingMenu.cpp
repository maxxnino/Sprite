#include "ScrollingMenu.h"

ScrollingMenu::ScrollingMenu(RectI rectMenu)
	:
	rectMenu(rectMenu),
	iconTexture(104,104)
{
	for (int y = 0; y < 104; y++)
	{
		for (int x = 0; x < 104; x++)
		{
			iconTexture.PutPixel(x, y, Colors::Black);
		}
	}
	
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
		buttons[i].Draw(rectMenu, gfx, iconTexture);
	}
}

void ScrollingMenu::Update(Mouse & mouse, Mouse::Event::Type& mouseEvent, float dt, Sound & sound, Sound & clickSound)
{
	if (mouseEvent == Mouse::Event::Type::WheelUp)
	{
		moveVertical = -(int)(speedScrolling * dt);
	}
	else if (mouseEvent == Mouse::Event::Type::WheelDown)
	{
		moveVertical = (int)(speedScrolling * dt);
	}
	else
	{
		moveVertical = 0;
	}
	for (auto& c : buttons)
	{
		c.MoveButtonVerical(moveVertical);
		c.Update(mouse, mouseEvent, dt, sound, clickSound);
	}
}
