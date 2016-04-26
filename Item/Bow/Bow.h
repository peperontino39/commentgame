
#pragma once
#include "../ItemBase.h"


class Bow : public ItemBase
{
public:

	Bow();
	~Bow();

	void use(Vec2f _pos, Direction _direction) override;
	void update() override;
	void draw() override;

private:


};