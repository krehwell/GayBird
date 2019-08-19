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
private:
	int x;
	int y;
	static constexpr int width = 70;
	static constexpr int height = 53;
	int vy = 5;
	bool enable = false;
};
