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
	for (int i = 0; i < amount; i++)
	{
		CallBlock(blockUp[i], blockDown[i]);
	}
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
	//allow = true;
}

void Game::UpdateModel()
{
	//if (gameSpeed > gameSpeedMax)
	//{
	if (!gameOver)
	{
		bird.Move();
		bird.ClampToScreen();
	}

	for (int i = 0; i < amount; i++)
	{
		if (!blockUp[i].CollusionDetect(bird) && !blockDown[i].CollusionDetect(bird) && !gameOver)
		{
			gameSpeed = 0;

			if (!blockUp[i].GetRegenerate() && blockAllow[i] == true)
			{
				blockUp[i].MoveBlock();
				blockUp[i].BlockClamp();
			}

			if (!blockDown[i].GetRegenerate() && blockAllow[i] == true)
			{
				blockDown[i].MoveBlock();
				blockDown[i].BlockClamp();
			}

		//	if (blockUp[i].GetRegenerate() && blockAllow[i] == true)
		//	{
		//		CallBlock(blockUp[i], blockDown[i]);
		//	}

			if (blockUp[i].GetX() <= blockGap && blockAllow[i] == true)
			{
				if (i == 2)
				{
					blockAllow[0] = true;
					if (blockUp[0].GetRegenerate())
					{
						CallBlock(blockUp[0], blockDown[0]);
					}
				}
				else
				{
					blockAllow[i+1] = true;
					if (blockUp[i+1].GetRegenerate())
					{
						CallBlock(blockUp[i+1], blockDown[i+1]);
					}
				}
			}

			if (blockUp[i].getBlockWidth() <= 0)
			{
				blockAllow[i] = false;
			}
		}
		else
		{
			gameOver = true;
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

	for (int i = 0; i < amount; i++)
	{
		if (blockAllow[i] == true)
		{
			blockUp[i].DrawBlockUp(gfx);
			blockDown[i].DrawBlockDown(gfx);
		}
	}
	//gfx.DrawRect(50, firstInitY, 140, Graphics::ScreenHeight, Colors::Gray);
}
