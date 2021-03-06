#pragma once
#include "../Enemy.h"
#include "../../Taxture/Taxtures.h"
class Slime : public Enemy
{
public:
	Slime();
	Slime(Vec2f _pos, Vec2f _size);
	~Slime();
	void update() override;
	void draw() override;
	void move() override;
	void addpos(Vec2f) override;
	void stan(Vec2f item_pos, Vec2f item_size) override;
	Vec2f ride(Vec2f player_pos, Vec2f player_size,Vec2f vec) override;
private:
	Vec2f ride_pos;
	Vec2f ride_size;
};