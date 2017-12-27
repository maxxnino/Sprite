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


bool Button::Update(Mouse& mouse, Mouse::Event::Type& mouseEvent, float dt, Sound& sound, Sound& clickSound)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		if (isPlaySound)
		{
			sound.Play();
			isPlaySound = false;
		}
		buttonColor = Colors::Yellow;
		if (mouseEvent == Mouse::Event::Type::LPress)
		{
			clickSound.Play();
			return true;
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
bool CraftButton::Update(Mouse & mouse, Mouse::Event::Type& mouseEvent, float dt, Sound& sound, Sound& clickSound)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		if (isPlaySound)
		{
			sound.Play();
			isPlaySound = false;
		}
		buttonColor = Colors::Yellow;
		if (mouseEvent == Mouse::Event::Type::LPress)
		{
			if (!IsEnableEffect)
			{
				clickSound.Play();
				IsEnableEffect = true;
			}
			CycleColor(dt);
			return true;
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
//ScrollingButton
ScrollingButton::ScrollingButton(RectI rectButton, Color buttonColor)
	:
	Button(rectButton, buttonColor)
{
	minDistance = rectButton.top - 500;
	maxDistance = rectButton.top;
	distance = rectButton.top;
}

void ScrollingButton::Draw(const RectI & rectMenu, Graphics & gfx, const Surface& iconTexture) const
{
	int xStart = rectButton.left;
	int xEnd = rectButton.right;
	int yStart = rectButton.top;
	int yEnd = rectButton.bottom;

	if (yStart >= rectMenu.bottom)
	{
		yStart = rectMenu.bottom;
	}
	if (yStart <= rectMenu.top)
	{
		yStart = rectMenu.top;
	}
	if (yEnd >= rectMenu.bottom)
	{
		yEnd = rectMenu.bottom;
	}
	if (yEnd <= rectMenu.top)
	{
		yEnd = rectMenu.top;
	}
	if (yStart != yEnd)
	{
		RectI rectDraw = { xStart, yStart, xEnd, yEnd };
		gfx.DrawSprite({ xStart,yStart }, rectDraw, iconTexture.GetRect(),iconTexture, SpriteEffect::CopyGhost());
		gfx.DrawRect(rectDraw, 4, buttonColor);
	}
}

void ScrollingButton::MoveButtonVerical(int distanct)
{
	distance += distanct;
	if (distance < minDistance)
	{
		distance = minDistance;
	}
	if (distance > maxDistance)
	{
		distance = maxDistance;
	}
	rectButton.top = distance;
	rectButton.bottom = distance + 104;
}
