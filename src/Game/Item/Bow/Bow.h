#pragma once
#include "Arrow/Arrow.h"



class Bow : public ItemBase
{
public:

	Bow();
	Bow(Vec2f _pos, Vec2f _size);
	~Bow();

	void putDownTheBow(const Vec2f& pos);
	Vec2f shootTheBow();

	void update() override;
	void draw() override;

	WritableP<Vec2f> arrow_vec;

private:

	void drawTheBow();
	void changeAngle();

	float max_arrow_vec;
	Vec2f arrow_vec_;
	float rad;
};