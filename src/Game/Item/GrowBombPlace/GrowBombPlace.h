#pragma once
#include "Bomb/Bomb.h"



class GrowBombPlace : public ItemBase
{
public:

	GrowBombPlace() ;
	GrowBombPlace(Vec2f pos, Vec2f size);
	~GrowBombPlace();

	Vec2f createBomb();

	void respawnTime();

	void setup();
	void update() override;
	void draw() override;

	WritableP<int> respawn_time;
	WritableP<bool> is_here_bomb;

private:

	bool is_here_bomb_;
	int max_respawn_time;
	int respawn_time_;
};