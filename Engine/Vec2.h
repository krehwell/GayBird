#pragma once
class Vec2
{
public:
	Vec2() = default;
	Vec2(float x, float y);
	Vec2 operator+(Vec2& rhs);
	Vec2& operator+=(Vec2& rhs);
	Vec2 operator*(float rhs);
	Vec2& operator*=(float rhs);

public:
	float x;
	float y;
};
