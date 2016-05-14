#pragma once
#include "../Bomb/Bomb.h"
#include "../GrowBombPlace.h"
#include "../../../Player/PlayerManager.h"



class BombManager
{
public:

	BombManager();
	~BombManager();

	void deleteitem();

	void createGrowBombPlace(Vec2f pos, Vec2f size);

	void setup(Vec2f pos, Vec2f size);
	void update();
	void draw();

private:

	void createBomb();
	void deleteBomb();
	void catchBomb();

	std::list<Bomb> bombs;
	std::list<GrowBombPlace> grow_bomb_places;
	Vec2f block_size;

};