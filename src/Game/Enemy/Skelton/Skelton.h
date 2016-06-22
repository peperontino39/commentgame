#pragma once
#include "../Enemy.h"
#include "../../Taxture/Taxtures.h"
class Skelton : public Enemy
{
public:
	Skelton() {};
	Skelton(Vec2f _pos, Vec2f _size);
	~Skelton();
	void update() override;
	void draw() override;
	void move() override;
	void addpos(Vec2f) override;
	bool attack(Vec2f player_pos, Vec2f player_size) override;
	Vec2f ride(Vec2f player_pos, Vec2f player_size, Vec2f vec) override;
private:
	Vec2f attack_pos;
	Vec2f attack_size;
	Vec2f buf_pos;
	Vec2f buf_size;
	int increment;
	int decrement;
	int setup;
};