#pragma once
#include "../../ItemBase.h"

enum class BombStatus
{
	GROWING,
	NORMAL,
	CATCHING,
	COUNTDOWN,
	EXPLOSION
};


class Bomb : public ItemBase
{
public:

	Bomb();
	Bomb(Vec2f _pos, Vec2f _size, Vec2f vec);
	~Bomb();

	bool getIsEnd() const { return is_end; }
	BombStatus getBombStatus() const { return bomb_status; }
	void setBombStatus(BombStatus bomb_status) { this->bomb_status = bomb_status; }
	void setCathcedPos(Vec2f catched_pos) { this->catxhed_pos = catched_pos; }
	void setCatchPos(Vec2f catch_pos) { this->catch_pos = catch_pos; }
	Vec2f getExplosionSize() const { return explosion_size; }
	Vec2f getBVec() const { return b_vec; }
	void setBVec(Vec2f b_vec) { this->b_vec = b_vec; }

	void update() override;
	void draw() override;

	Vec2f getBVec();

private:

	void Respawn();
	void catching();
	void countDown();
	void animation();
	void updatePos();

	float catching_count;
	Vec2f catxhed_pos;
	Vec2f catch_pos;
	int animation_count2;
	int animation_frame;
	bool is_end;
	float respawn_time;
	int index2;
	int index_y;
	Vec2f explosion_size;
	BombStatus bomb_status;
	Vec2f b_vec;

};