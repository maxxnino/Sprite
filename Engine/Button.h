#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "Mouse.h"
#include "SpriteEffect.h"
#include "SoundEffect.h"
#include <vector>


class Button
{
public:
	Button(RectI rectButton, Color buttonColor);
	void Draw(Graphics& gfx) const;
	bool Update(Mouse& mouse, float dt, Sound& sound, Sound& clickSound);
protected:
	RectI rectButton;
	bool isPlaySound = false;
	Color buttonColor;
};
class CraftButton : public Button
{
public:
	CraftButton(RectI rectButton, Color buttonColor)
		:
		Button(rectButton, buttonColor)
	{}
	bool Update(Mouse& mouse, float dt, Sound& sound, Sound& clickSound);
	void CycleColor(float dt);
private:
	std::vector<Color> ColorCycle = { Colors::Green,Colors::Red,Colors::Magenta };
	bool IsEnableEffect = false;
	float effectTime = 1.0f;
	float curEffectTime = 0.0f;
	float timeEachColor = 0.3f;
	float holdColor = 0.0f;
	int indexColor = 0;
};

class ElementSlot : public Button
{
public:
	enum ElementType
	{
		Fire,
		Water,
		Earth,
		Lighting,
		Nature,
		Wind,
		None
	};
	ElementSlot(RectI rectButton, Color buttonColor, ElementType elementType = ElementType::None);
	void ChangeType(ElementSlot::ElementType element);
	void Draw(Graphics& gfx, const Surface& iconTexture) const;
	const ElementType& GetType() const;
private:
	ElementType elementType;
	Color insideColor;
};

class ElementButton : public ElementSlot
{
public:
	ElementButton(RectI rectButton, Color buttonColor, ElementType elementType = ElementType::None)
		:
		ElementSlot(rectButton, buttonColor, elementType)
	{}
	void Draw(Graphics& gfx, const std::vector<Surface>& iconTexture) const;
};

class ScrollingButton : public Button
{
public:
	ScrollingButton(RectI rectButton, Color buttonColor);
	void Draw(const RectI& rectMenu, Graphics& gfx) const;
	void MoveButtonVerical(int distanct);
private:
	int minDistance;
	int maxDistance;
	int distance;
};
