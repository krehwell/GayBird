#pragma once
#include "Graphics.h"
#include "Bird.h"
#include <random>

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
	void DeniedRegenerate();
	int getBlockWidth();
	int GetX();

	~Block();
private:
	int x = Graphics::ScreenWidth;
	int y = 0;
	int height;
	int blockMove = 1;
	int initWidth = 100;
	int width = initWidth;
	bool dead=false;
	bool regenerate = false;
};

