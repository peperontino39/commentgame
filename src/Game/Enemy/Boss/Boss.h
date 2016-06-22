#pragma once
#include "../Enemy.h"
#include "../../Taxture/Taxtures.h"
#include "Fire.h"
class Boss : public Enemy
{
public:
	Boss();
	Boss(Vec2f _pos, Vec2f _size);
	~Boss();
	void update() override;
	void draw() override;
	void move() override;
	void addpos(Vec2f) override;
	bool attack(Vec2f player_pos, Vec2f player_size) override;
	void breath();
	void blade();
	Vec2f ride(Vec2f player_pos, Vec2f player_size, Vec2f vec) override;
	void changeDirection(Vec2f player_pos);
private:
	int attack_count;
	int attack_type;
	Vec2f attack_pos;
	Vec2f attack_size;
	std::vector<std::shared_ptr<Fire>> fire;
};