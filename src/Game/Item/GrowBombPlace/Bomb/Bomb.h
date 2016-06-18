#pragma once
#include "../../ItemBase.h"


class Bomb : public ItemBase
{
public:

	Bomb();
	Bomb(Vec2f _pos, Vec2f _size, Vec2f vec);
	~Bomb();

	bool getIsExplosion() const { return is_explosion; }
	bool getIsRespawnBomb() const { return is_respawn_bomb; }
	void setIsRespawnBomb(bool is_respawn_bomb) { this->is_respawn_bomb = is_respawn_bomb; }

	void update() override;
	void draw() override;

private:

	void countDown();
	void animation();
	void updatePos();

	int respawn_time;
	int explosion_count;
	int explosion_end_count;
	int animation_count;
	bool is_explosion;
	bool is_respawn_bomb;

	Vec2f cut_pos;
	Vec2f cut_size;
	Vec3f color;

};