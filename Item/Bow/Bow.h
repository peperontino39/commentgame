#pragma once
#include "../ItemBase.h"


class Bow : public ItemBase
{
public:

	Bow();
	Bow(Vec2f _pos, Vec2f _size);
	~Bow();

	void update() override;
	void draw() override;

private:


};