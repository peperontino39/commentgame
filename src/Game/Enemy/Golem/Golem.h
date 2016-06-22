#pragma once
#include "../Enemy.h"
#include "../../Taxture/Taxtures.h"
class Golem : public Enemy
{
public:
	Golem() {};
	Golem(Vec2f _pos, Vec2f _size);
	~Golem();
	void update() override;
	void draw() override;
	void move() override;
	Vec2f ride(Vec2f player_pos, Vec2f player_size, Vec2f vec) override;

private:

};