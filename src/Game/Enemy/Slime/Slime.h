#pragma once
#include "../Enemy.h"
class Slime : public Enemy
{
public:
	Slime();
	Slime(Vec2f _pos, Vec2f _size);
	~Slime();
	void update() override;
	void draw() override;
	void stan(Vec2f pos, Vec2f size) override;

private:

};