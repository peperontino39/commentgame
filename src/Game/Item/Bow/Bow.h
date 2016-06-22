#pragma once
#include "Arrow/Arrow.h"


enum class BowStatus
{
	NOMAL,
	DRAW,
	SHOOT
};


class Bow : public ItemBase
{
public:

	Bow();
	Bow(Vec2f _pos, Vec2f _size);
	~Bow();

	Vec2f getArrowVec() const { return arrow_vec; }
	BowStatus getBowStatus() const { return bow_status; }
	float getRad() const { return rad; }

	void putDownTheBow(const Vec2f& pos);
	Vec2f shootTheBow();

	void update() override;
	void draw() override;

private:

	void drawTheBow();
	void changeAngle();

	BowStatus bow_status;
	float max_arrow_vec;
	Vec2f arrow_vec;
	float rad;
};