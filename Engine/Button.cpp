#include "Button.h"

Button::Button(RectI rectButton, Color buttonColor, TypeElement typeEle)
	:
	rectButton(rectButton),
	buttonColor(buttonColor),
	typeEle(typeEle)
{}

//father

void Button::updateMouse(Mouse & mouse)
{
	if (rectButton.isContaint(mouse.GetPos()))
	{
		buttonColor = Colors::Green;
		while (!mouse.IsEmpty())
		{
			const Mouse::Event e = mouse.Read();
			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				Clicked();
			}
		}
	}
	else
	{
		buttonColor = Colors::Yellow;
	}
}

void Button::ChangeElement(TypeElement newElement)
{
	typeEle = newElement;
}

void Button::ChangeColor(Color c)
{
	buttonColor = c;
}

void Button::Clicked()
{
	isClicked = true;
}


//Child class

CreateSkill::CreateSkill(RectI rectButton, Color buttonColor, TypeElement typeEle)
	:
	Button(rectButton, buttonColor, typeEle)
{}

void CreateSkill::Update(Mouse & mouse, Menu& menu, Button* whocall)
{

	Button::updateMouse(mouse);
	if (isClicked)
	{
		ChangeColor(Colors::Blue);
	}
}

void CreateSkill::Draw(Graphics & gfx, const Menu & menu) 
{
	gfx.DrawRect(rectButton, 10, buttonColor);
}

CraftSlot::CraftSlot(RectI rectButton, Color buttonColor, TypeElement typeEle)
	:
	Button(rectButton, buttonColor, typeEle)
{}

void CraftSlot::Update(Mouse & mouse, Menu& menu, Button* whocall)
{
	Button::updateMouse(mouse);
	if (isClicked)
	{
		menu.ChangeState();
	}
}

void CraftSlot::Draw(Graphics & gfx, const Menu & menu)
{
	gfx.DrawRect(rectButton, 10, buttonColor);
}

ElementSlot::ElementSlot(RectI rectButton, Color buttonColor, TypeElement typeEle)
	:
	Button(rectButton, buttonColor, typeEle)
{}

void ElementSlot::Update(Mouse & mouse, Menu & menu, Button* whocall)
{
	Button::updateMouse(mouse);
	if (isClicked)
	{
		menu.ChangeState();
		whocall->ChangeElement(typeEle);
	}
}

void ElementSlot::Draw(Graphics & gfx, const Menu & menu) 
{
	if (menu.GetState() == Menu::TypeMenu::SelectElement)
	{
		gfx.DrawRect(rectButton, 10, buttonColor);
	}
}
