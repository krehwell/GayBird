#include "Block.h"

void Block::InitBlock(int _height)
{
	height = _height;
}

void Block::DrawBlock(Graphics & gfx)
{
	if (x + width > Graphics::ScreenWidth)
	{
		int widthTemp = Graphics::ScreenWidth;
		gfx.DrawRect(x, y, widthTemp, height, Colors::Green);
	}
	else
	{
		gfx.DrawRectDim(x, y, width, height, Colors::Green);
	}
}

void Block::MoveBlock()
{
	x -= blockMove;
}

void Block::BlockClamp()
{
	if (x <= 0)
	{
		x = 0;
		width -= blockMove;
	}
	if (width <= 0)
	{
		width = 0;
		Block::~Block();
	}
}

Block::~Block()
{
}
