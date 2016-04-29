#pragma once
#include "Arrow/Arrow.h"


class Bow : public ItemBase
{
public:

	Bow();
	Bow(Vec2f _pos, Vec2f _size, Vec2f _vec);
	~Bow();

	void update() override;
	void draw() override;

private:

	void drawTheBow();
	void shootTheBow();

	float rad;
	Vec2f arrow_vec;
	int arrows_max_num;
	std::list<Arrow> arrows;
};