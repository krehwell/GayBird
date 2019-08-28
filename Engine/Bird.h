#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Bird
{
public:
	Bird(float _x, float _y);
	void DrawBird(Graphics& gfx);
	void Move(float dt);
	void ClampToScreen();
	float BirdXSize();
	float BirdYSize();
	float GetBirdX();
	float GetBirdY();
	bool isJumped();
private:
	float x;
	float y;
	static constexpr float width = 70.0f;
	static constexpr float height = 53.0f;
	float vy = 1.0f;
	bool enable = false;
	bool inhibit = false;
	bool soundPlay = false;
};
