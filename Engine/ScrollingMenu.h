#pragma once
#include "Button.h"
#include <vector>

class ScrollingMenu
{
public:
	ScrollingMenu(RectI rectMenu);
	void Draw(Graphics& gfx, const Font& font) const;
	void Update(Mouse& mouse, Mouse::Event::Type& mouseEvent, const std::string& skillName,float dt, Sound& sound, Sound& clickSound);
private:
	std::vector<ScrollingButton> buttons;
	RectI rectMenu;
	static constexpr int nButton = 8;
	int moveVertical = 0;
	static constexpr float speedScrolling = 1500;
	static constexpr int buttonDismention = 104;
	static constexpr int buttonPadding = 20;
	Surface iconTexture;
};