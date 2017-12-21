#pragma once
#include "Menu.h"
#include "Graphics.h"
#include "Mouse.h"
#include <vector>

enum TypeElement
{
	Fire,
	Water,
	Lighting,
	Wind,
	Earth,
	None
};
class Button
{
public:
	Button(RectI rectButton, Color buttonColor, TypeElement typeEle = TypeElement::None);
	virtual void Draw(Graphics& gfx, const Menu& menu) = 0;
	void updateMouse(Mouse& mouse);
	virtual void Update(Mouse& mouse, Menu& menu, Button* whocall) = 0;
	void ChangeElement(TypeElement newElement);
	void ChangeColor(Color c);
	void Clicked();
	virtual ~Button(){}
	//Accesser
protected:
	TypeElement typeEle;
	RectI rectButton;
	Color buttonColor;
	bool isClicked = false;
};

//Child class

class CreateSkill : public Button
{
public:
	CreateSkill(RectI rectButton, Color buttonColor, TypeElement typeEle = TypeElement::None);
	virtual void Update(Mouse& mouse, Menu& menu, Button* whocall) override;
	virtual void Draw(Graphics& gfx, const Menu& menu) override;
};

class CraftSlot : public Button
{
public:
	CraftSlot(RectI rectButton, Color buttonColor, TypeElement typeEle = TypeElement::None);
	virtual void Update(Mouse& mouse, Menu& menu, Button* whocall) override;
	virtual void Draw(Graphics& gfx, const Menu& menu) override;
};

class ElementSlot : public Button
{
public:
	ElementSlot(RectI rectButton, Color buttonColor, TypeElement typeEle = TypeElement::None);
	virtual void Update(Mouse& mouse, Menu& menu, Button* whocall) override;
	virtual void Draw(Graphics& gfx, const Menu& menu) override;
};