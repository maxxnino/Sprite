#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include <vector>


class Button
{
public:
	Button(RectI rectButton, Color buttonColor);
	void Draw(Graphics& gfx) const;
	bool Update(Mouse& mouse, float dt);
protected:
	RectI rectButton;
	Color buttonColor;
};
class CraftButton : public Button
{
public:
	CraftButton(RectI rectButton, Color buttonColor)
		:
		Button(rectButton, buttonColor)
	{}
	bool Update(Mouse& mouse, float dt);
	void CycleColor(float dt);
private:
	std::vector<Color> ColorCycle = { Colors::Blue,Colors::Red,Colors::Magenta };
	bool IsEnableEffect = false;
	float effectTime = 1.0f;
	float curEffectTime = 0.0f;
	float timeEachColor = 0.3f;
	float holdColor = 0.0f;
	int indexColor = 0;
};

class ElementButton : public Button
{
public:

	enum ElementType
	{
		Fire,
		Water,
		Earth,
		Lighting,
		Ice,
		Wind,
		None
	};
	ElementButton(RectI rectButton, Color buttonColor, ElementType elementType);
	void ChangeType(ElementButton::ElementType element);
	void Draw(Graphics& gfx) const;
	const ElementType& GetType() const;
	void changeColor(ElementType element);
private:
	ElementType elementType = None;
	Color insideColor;
};
