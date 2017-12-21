/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteEffect.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	menu(1)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	if (wnd.kbd.KeyIsPressed('I'))
	{
		gameState = 1;
	}
	if (wnd.kbd.KeyIsPressed('O'))
	{
		gameState = 0;
	}
	if (gameState == 0)
	{
		VecF dir = { 0.0f,0.0f };
		if (wnd.kbd.KeyIsPressed('A'))
		{
			dir.x = -1.0f;
		}
		if (wnd.kbd.KeyIsPressed('D'))
		{
			dir.x = 1.0f;
		}
		if (wnd.kbd.KeyIsPressed('W'))
		{
			dir.y = -1.0f;
		}
		if (wnd.kbd.KeyIsPressed('S'))
		{
			dir.y = 1.0f;
		}
		link.SetDirection(dir);
		link.Update(dt);
	}
	else
	{
		menu.Update(wnd.mouse, dt);
	}
}

void Game::ComposeFrame()
{
	if (gameState == 1)
	{
		menu.Draw(gfx);
	}
	else
	{
		link.Draw(gfx);
	}
}
