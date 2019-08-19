#pragma once
#include "Graphics.h"
#include "Bird.h"

class Block
{
public:
	void InitBlock(int _height);
	void DrawBlock(Graphics& gfx);
	void MoveBlock();
	void BlockClamp();
	void CollusionDetect(Bird bird);

	~Block();
private:
	int x = Graphics::ScreenWidth;
	int y = 0;
	int height;
	int blockMove = 5;
	int width = 100;
};

