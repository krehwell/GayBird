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
	yDist(20, 400)
{
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
	std::random_device rds;
	std::mt19937 rngs(rds());
	int firstInitY = yDist(rngs);
	blockUp.InitBlock(firstInitY);
	blockDown.InitBlock(firstInitY + gap);

	blockUp.DeniedRegenerate();
	blockDown.DeniedRegenerate();
}

void Game::UpdateModel()
{
	//if (gameSpeed > gameSpeedMax)
	//{
	if (!blockUp.CollusionDetect(bird) && !blockDown.CollusionDetect(bird))
	{
		gameSpeed = 0;
		bird.Move();
		bird.ClampToScreen();

		if (!blockUp.GetRegenerate())
		{
			blockUp.MoveBlock();
			blockUp.BlockClamp();
		}
		if (!blockDown.GetRegenerate())
		{
			blockDown.MoveBlock();
			blockDown.BlockClamp();
		}
		if (blockUp.GetRegenerate())
		{
			CallBlock();
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
	blockUp.DrawBlockUp(gfx);
	blockDown.DrawBlockDown(gfx);

	//gfx.DrawRect(50, firstInitY, 140, Graphics::ScreenHeight, Colors::Gray);
}
