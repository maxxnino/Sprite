#pragma once
#include "Button.h"
#include <vector>

class ScrollingMenu
{
public:
	ScrollingMenu(RectI rectMenu);
	void Draw(Graphics& gfx) const;
	void Update(Mouse& mouse, float dt, Sound& sound, Sound& clickSound);
private:
	std::vector<ScrollingButton> buttons;
	RectI rectMenu;
	static constexpr int nButton = 8;
	int moveVertical = 0;
	static constexpr float speedScrolling = 200;
	static constexpr int buttonDismention = 104;
	static constexpr int buttonPadding = 20;
};