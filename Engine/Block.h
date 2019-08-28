#pragma once
#include "Graphics.h"
#include "Bird.h"
#include <random>

class Block
{
public:
	void InitBlock(float _height);
	void DrawBlockUp(Graphics& gfx);
	void DrawBlockDown(Graphics& gfx);
	void MoveBlock(float dt);
	void BlockClamp(float dt);
	bool CollusionDetect(Bird bird);
	bool GetRegenerate();
	void DeniedRegenerate();
	float getBlockWidth();
	float GetX();

	~Block();
private:
	float x = Graphics::ScreenWidth;
	float y = 0.0f;
	float height;
	float blockMove = 1.0f * 60.0f;
	float initWidth = 100.0f;
	float width = initWidth;
	bool dead = false;
	bool regenerate = false;
};

