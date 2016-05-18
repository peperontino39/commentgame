#pragma once
#include "../Enemy.h"
class Skelton : public Enemy
{
public:
	Skelton();
	Skelton(Vec2f _pos, Vec2f _size);
	~Skelton();
	void update() override;
	void draw() override;
	void move() override;
	void stan(Vec2f item_pos, Vec2f item_size) override;
	bool kill(Vec2f player_pos, Vec2f player_size) override;
	bool attack(Vec2f player_pos, Vec2f player_size) override;

private:

};