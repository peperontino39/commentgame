#pragma once
#include "../../ItemBase.h"


class Bomb : public ItemBase
{
public:

	Bomb();
	Bomb(Vec2f _pos, Vec2f _size, Vec2f vec);
	~Bomb();

	void update() override;
	void draw() override;

	WritableP<bool> is_explosion;
	WritableP<bool> is_respawn_bomb;

private:

	void countDown();
	void animation();
	void updatePos();

	int respawn_time;
	int explosion_count;
	int explosion_end_count;
	int animation_count;
	bool is_explosion_;
	bool is_respawn_bomb_;

	Vec2f cut_pos;
	Vec2f cut_size;
	Vec3f color;

};