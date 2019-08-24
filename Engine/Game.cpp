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
	CallBlock(blockUp, blockDown);
	CallBlock(blockUp1, blockDown1);
	CallBlock(blockUp2, blockDown2);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::CallBlock(Block &blockCallUp, Block &blockCallDown)
{
	std::random_device rds;
	std::mt19937 rngs(rds());
	//std::uniform_int_distribution<int> yDists(1, 400);
	int firstInitY = yDist(rngs);
	blockCallUp.InitBlock(firstInitY);
	blockCallDown.InitBlock(firstInitY + gap);

	blockCallUp.DeniedRegenerate();
	blockCallDown.DeniedRegenerate();
}

void Game::UpdateModel()
{
	//if (gameSpeed > gameSpeedMax)
	//{
	if (!blockUp.CollusionDetect(bird) && !blockDown.CollusionDetect(bird) && 
		!blockUp1.CollusionDetect(bird) && !blockDown1.CollusionDetect(bird) &&
		!blockUp2.CollusionDetect(bird) && !blockDown2.CollusionDetect(bird))
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
			CallBlock(blockUp, blockDown);
		}

		if (blockUp.GetX() <= 375)
		{
			block1Allow = true;
		}

		if (block1Allow == true)
		{
			if (!blockUp1.GetRegenerate())
			{
				blockUp1.MoveBlock();
				blockUp1.BlockClamp();
			}
			if (!blockDown1.GetRegenerate())
			{
				blockDown1.MoveBlock();
				blockDown1.BlockClamp();
			}
			if (blockUp1.GetRegenerate())
			{
				CallBlock(blockUp1, blockDown1);
			}
		}

		if (blockUp1.GetX() <= 570)
		{
			block2Allow = true;
		}

		if (block2Allow == true)
		{
			if (!blockUp2.GetRegenerate())
			{
				blockUp2.MoveBlock();
				blockUp2.BlockClamp();
			}
			if (!blockDown2.GetRegenerate())
			{
				blockDown2.MoveBlock();
				blockDown2.BlockClamp();
			}
			if (blockUp2.GetRegenerate())
			{
				CallBlock(blockUp2, blockDown2);
			}
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

	if (block1Allow == true)
	{
   		blockUp1.DrawBlockUp(gfx);
		blockDown1.DrawBlockDown(gfx);
	}

	if (block2Allow == true)
	{
		blockUp2.DrawBlockUp(gfx);
		blockDown2.DrawBlockDown(gfx);
	}
	//gfx.DrawRect(50, firstInitY, 140, Graphics::ScreenHeight, Colors::Gray);
}
