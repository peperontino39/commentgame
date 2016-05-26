#pragma once
#include "Arrow/Arrow.h"



class Bow : public ItemBase
{
public:

	Bow();
	Bow(Vec2f _pos, Vec2f _size);
	~Bow();

	Vec2f getArrowVec() const { return arrow_vec; }

	void putDownTheBow(const Vec2f& pos);
	Vec2f shootTheBow();

	void update() override;
	void draw() override;

private:

	void drawTheBow();
	void changeAngle();

	float max_arrow_vec;
	Vec2f arrow_vec;
	float rad;
};