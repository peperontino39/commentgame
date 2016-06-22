#pragma once
#include "../../ItemBase.h"


class Arrow : public ItemBase
{
public:

	Arrow();
	Arrow(Vec2f _pos, Vec2f _size, Vec2f _vec, float rad);
	~Arrow();

	void setRad(float rad) { this->rad = rad; }

	void update() override;
	void draw() override;

private:

	void move();
	float rad;

};