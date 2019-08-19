#include "Block.h"

void Block::InitBlock(int _x, int _height)
{
	x = _x;
	height = _height;
}

void Block::DrawBlock(Graphics & gfx)
{
	gfx.DrawRectDim(x, y, width, height, Colors::Green);
}
