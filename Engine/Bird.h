#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Bird
{
public:
	Bird(int _x, int _y);
	void DrawBird(Graphics& gfx);
	void Move();
	void ClampToScreen();
	int BirdXSize();
	int BirdYSize();
	int GetBirdX();
	float GetBirdY();
	bool isJumped();
private:
	int x;
	float y;
	static constexpr int width = 70;
	static constexpr int height = 53;
	float vy = 1;
	bool enable = false;
	bool inhibit = false;
	bool soundPlay = false;
};
