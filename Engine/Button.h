#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "Mouse.h"
#include "SpriteEffect.h"
#include "SoundEffect.h"
#include "Skill.h"
#include "Font.h"
#include <algorithm>
#include <vector>


class Button
{
public:
	Button(RectI rectButton, Color buttonColor);
	void Draw(Graphics& gfx) const;
	bool Update(Mouse& mouse, Mouse::Event::Type& mouseEvent, float dt, Sound& sound, Sound& clickSound);
protected:
	RectI rectButton;
	bool isPlaySound = false;
	Color buttonColor;
};

class ElementSlot : public Button
{
public:
	enum ElementType
	{
		Fire,
		Water,
		Lighting,
		Earth,
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

class CraftButton : public Button
{
public:
	CraftButton(RectI rectButton, Color buttonColor)
		:
		Button(rectButton, buttonColor)
	{}
	bool Update(Mouse& mouse, Mouse::Event::Type& mouseEvent, float dt, const std::vector<ElementButton>& element,Sound& sound, Sound& clickSound);
	void CraftSKill(const std::vector<ElementButton>& element);
	void CycleColor(float dt);
	char* ConvertElementToString(const ElementButton& e) const;
	const std::string& GetSKillSet() const;
private:
	std::vector<Color> ColorCycle = { Colors::Green,Colors::Red,Colors::Magenta };
	std::string skillSet = "";
	SkillLookup lookup;
	bool IsEnableEffect = false;
	static constexpr float effectTime = 1.0f;
	float curEffectTime = 0.0f;
	static constexpr float timeEachColor = 0.25f;
	float holdColor = 0.0f;
	int indexColor = 0;
};

class SkillButton : public Button
{
public:
	SkillButton(RectI rectButton, Color buttonColor, CraftButton craftButton)
		:
		Button(rectButton, buttonColor),
		skillName(craftButton.GetSKillSet()),
		iconTexture(104, 104)
	{
		for (int y = 0; y < 104; y++)
		{
			for (int x = 0; x < 104; x++)
			{
				iconTexture.PutPixel(x, y, Colors::Black);
			}
		}
	}
	void Update(Mouse& mouse, Mouse::Event::Type& mouseEvent, float dt, const CraftButton& craftbutton,Sound& sound, Sound& clickSound);
	void Draw(Graphics& gfx, const Font& font) const;
	const std::string& GetSkillName() const;
private:
	Surface iconTexture;
	std::string skillName;
};
class ScrollingButton : public Button
{
public:
	ScrollingButton(RectI rectButton, Color buttonColor);
	void Draw(const RectI& rectMenu, Graphics& gfx,const Font& font, const Surface& iconTexture) const;
	void Update(Mouse& mouse, Mouse::Event::Type& mouseEvent, const std::string& skillName, float dt, Sound& sound, Sound& clickSound);
	void MoveButtonVerical(int distanct);
private:
	int minDistance;
	int maxDistance;
	int distance;
	std::string skillName = "";
};
