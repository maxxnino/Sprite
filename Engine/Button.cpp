#include "Button.h"

Button::Button(RectI rectButton, Color buttonColor)
	:
	rectButton(rectButton),
	buttonColor(buttonColor)
{}

void Button::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rectButton, 10, buttonColor);
}


bool Button::Update(Mouse& mouse, float dt)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		buttonColor = Colors::Blue;
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();
			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				return true;
			}
		}
	}
	else
	{
		buttonColor = Colors::Yellow;
	}
	return false;
}

//ElementButton
ElementButton::ElementButton(RectI rectButton, Color buttonColor, ElementType elementType)
		:
	Button(rectButton, buttonColor),
	elementType(elementType)
{
	changeColor(elementType);
}

void ElementButton::ChangeType(ElementButton::ElementType element)
{
	elementType = element;
	changeColor(element);
}

void ElementButton::Draw(Graphics & gfx) const
{
	gfx.DrawRectAndColor(rectButton, 10, buttonColor, insideColor);
}

const ElementButton::ElementType& ElementButton::GetType() const
{
	return elementType;
}

void ElementButton::changeColor(ElementType element)
{
	switch (element)
	{
	case ElementButton::Fire:
		insideColor = Colors::MakeRGB(251, 203, 98);
		break;
	case ElementButton::Water:
		insideColor = Colors::MakeRGB(103, 216, 236);
		break;
	case ElementButton::Earth:
		insideColor = Colors::MakeRGB(73, 43, 19);
		break;
	case ElementButton::Lighting:
		insideColor = Colors::MakeRGB(14, 96, 96);
		break;
	case ElementButton::Ice:
		insideColor = Colors::MakeRGB(99, 213, 212);
		break;
	case ElementButton::Wind:
		insideColor = Colors::MakeRGB(16, 149, 103);
		break;
	case ElementButton::None:
		insideColor = Colors::White;
		break;
	default:
		insideColor = Colors::Magenta;
		break;
	}
}

//CraftButton
bool CraftButton::Update(Mouse & mouse, float dt)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		buttonColor = Colors::Blue;
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();
			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				if (!IsEnableEffect)
				{
					IsEnableEffect = true;
				}
				CycleColor(dt);
				return true;
			}
		}
	}
	else
	{
		buttonColor = Colors::Yellow;
	}
	CycleColor(dt);
	return false;
}

void CraftButton::CycleColor(float dt)
{
	if (IsEnableEffect)
	{
		curEffectTime += dt;
		holdColor += dt;
		while (holdColor >= timeEachColor)
		{
			holdColor -= timeEachColor;
			indexColor++;
			if (indexColor >= ColorCycle.size())
			{
				indexColor = 0;
			}
		}
		buttonColor = ColorCycle[indexColor];
		if (curEffectTime >= effectTime)
		{
			curEffectTime = 0.0f;
			holdColor = 0.0f;
			indexColor = 0;
			IsEnableEffect = false;
			buttonColor = Colors::Yellow;
		}
	}
}
