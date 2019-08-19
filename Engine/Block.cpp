#include "Block.h"

void Block::InitBlock(int _height)
{
	height = _height;
}

void Block::DrawBlockUp(Graphics & gfx)
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

void Block::DrawBlockDown(Graphics & gfx)
{
	y = height;
	
	if (x + width > Graphics::ScreenWidth)
	{
		int widthTemp = Graphics::ScreenWidth;
		gfx.DrawRect(x, y, widthTemp, Graphics::ScreenHeight, Colors::Green);
	}
	else
	{
		gfx.DrawRect(x, y, x+width, Graphics::ScreenHeight, Colors::Green);
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

bool Block::CollusionDetect(Bird bird)
{
	int blockHeight = y + height;
	int blockWidth = x + width;

	return
		bird.BirdXSize() >= x &&
		bird.GetBirdX()  <  blockWidth &&
		bird.BirdYSize() >= y &&
		bird.GetBirdY()  <  blockHeight;
}

bool Block::GetRegenerate()
{
	return regenerate;
}

int Block::GetX()
{
	return x;
}

Block::~Block()
{
	regenerate = true;
	x = Graphics::ScreenWidth;
}
