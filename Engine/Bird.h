#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"

class Bird
{
public:
	Bird(Vec2& pos_in);
	void DrawBird(Graphics& gfx);
	void Move(float dt);
	void ClampToScreen();
	float BirdXSize();
	float BirdYSize();
	Vec2& GetBirdPos();
	bool isJumped();
private:
	Vec2 pos;
	static constexpr float width = 70.0f;
	static constexpr float height = 53.0f;
	float vy = 1.0f;
	bool enable = false;
	bool inhibit = false;
	bool soundPlay = false;
};
