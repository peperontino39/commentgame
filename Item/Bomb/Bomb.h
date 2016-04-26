#pragma once
#include "../ItemBase.h"


class Bomb : public ItemBase
{
public:

	Bomb();
	Bomb(Vec2f _pos, Vec2f _size);
	~Bomb();

	void use(Vec2f _pos, Direction _direction) override;
	void update() override;
	void draw() override;

private:


};