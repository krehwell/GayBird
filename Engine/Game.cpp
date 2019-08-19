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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	bird(200, 300),
	rng(rd()),
	yDist(60, 320)
{
	bool allowFirst = true;
	blockUp[0].SetRegenerate(allowFirst);
	blockDown[0].SetRegenerate(allowFirst);
	CallBlock();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::CallBlock()
{
	bool allow = true;
	int i = 0;
	int firstInitY = yDist(rng);

	blockUp[i].InitBlock(firstInitY);
	blockDown[i].InitBlock(firstInitY + gap);

	if (blockUp[i].GetX() <= 400)
	{
		++i;
		blockUp[i].SetRegenerate(allow);
		blockDown[i].SetRegenerate(allow);
	}
}

void Game::UpdateModel()
{
	//if (gameSpeed > gameSpeedMax)
	//{
	for (int i = 0; i < totalBlock; i++)
	{
		if (!blockUp[i].CollusionDetect(bird) && !blockDown[i].CollusionDetect(bird))
		{
			gameSpeed = 0;
			bird.Move();
			bird.ClampToScreen();

			//	if (!blockUp.GetRegenerate())
			//	{
			blockUp[i].MoveBlock();
			blockUp[i].BlockClamp();
			//	}
			//	if (!blockDown.GetRegenerate())
			//	{
			blockDown[i].MoveBlock();
			blockDown[i].BlockClamp();
			//	}
		}
	}
	//}
	//else
	//{
	//	gameSpeed++;
	//}
}

void Game::ComposeFrame()
{
	bird.DrawBird(gfx);
	for (int i = 0; i < totalBlock; i++)
	{
		if (blockUp[i].GetRegenerate())
		{
			blockUp[i].DrawBlockUp(gfx);
			blockDown[i].DrawBlockDown(gfx);
		}
	}

	//gfx.DrawRect(50, firstInitY, 140, Graphics::ScreenHeight, Colors::Gray);
}
