#include "Button.h"

Button::Button(RectI rectButton, Color buttonColor)
	:
	rectButton(rectButton),
	buttonColor(buttonColor)
{}

void Button::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rectButton, 4, buttonColor);
}


bool Button::Update(Mouse& mouse, float dt, Sound& sound, Sound& clickSound)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		if (isPlaySound)
		{
			sound.Play();
			isPlaySound = false;
		}
		buttonColor = Colors::Yellow;
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();
			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				clickSound.Play();
				return true;
			}
		}
	}
	else
	{
		isPlaySound = true;
		buttonColor = Colors::Blue;
	}
	return false;
}


//ElementSlot
ElementSlot::ElementSlot(RectI rectButton, Color buttonColor, ElementType elementType)
		:
	Button(rectButton, buttonColor),
	elementType(elementType)
{}

void ElementSlot::ChangeType(ElementSlot::ElementType element)
{
	elementType = element;
}

void ElementSlot::Draw(Graphics & gfx, const Surface& iconTexture) const
{
	gfx.DrawSprite({ rectButton.left,rectButton.top }, iconTexture, SpriteEffect::Copy());
	Button::Draw(gfx);
}

const ElementSlot::ElementType& ElementSlot::GetType() const
{
	return elementType;
}

//CraftButton
bool CraftButton::Update(Mouse & mouse, float dt, Sound& sound, Sound& clickSound)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		if (isPlaySound)
		{
			sound.Play();
			isPlaySound = false;
		}
		buttonColor = Colors::Yellow;
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();
			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				clickSound.Play();
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
		isPlaySound = true;
		buttonColor = Colors::Blue;
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
			buttonColor = Colors::Blue;
		}
	}
}

//ElementButton
void ElementButton::Draw(Graphics & gfx, const std::vector<Surface>& iconTexture) const
{
	if (GetType() != ElementType::None)
	{
		gfx.DrawSprite({ rectButton.left,rectButton.top }, iconTexture[(int)GetType()], SpriteEffect::Copy());
	}
	Button::Draw(gfx);
}
