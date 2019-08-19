#pragma once
#include "Graphics.h"

class Block
{
public:
	void InitBlock(int _x, int _height);
	void DrawBlock(Graphics& gfx);
private:
	int x;
	int y = 0;
	int height;
	static constexpr int width = 80;
};