#pragma once
#include "Graphics.h"
#include "Bird.h"

class Block
{
public:
	void InitBlock(int _height);
	void DrawBlockUp(Graphics& gfx);
	void DrawBlockDown(Graphics& gfx);
	void MoveBlock();
	void BlockClamp();
	bool CollusionDetect(Bird bird);
	bool GetRegenerate();
	int GetX();
	~Block();
private:
	int x = Graphics::ScreenWidth;
	int y = 0;
	int height;
	int blockMove = 1;
	int width = 100;
	bool dead=false;
	bool regenerate = false;
};

