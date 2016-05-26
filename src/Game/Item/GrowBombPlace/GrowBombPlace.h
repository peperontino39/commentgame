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

	bool getIsHereBomb() const { return is_here_bomb; }
	void setIsHereBomb(bool is_here_bomb) { this->is_here_bomb = is_here_bomb; }
	int getRespawnTime() const { return respawn_time; }

	void setup();
	void update() override;
	void draw() override;

private:

	bool is_here_bomb;
	int max_respawn_time;
	int respawn_time;
};