#pragma once
#include "../Bow/BowManager/BowManager.h"
#include "../GrowBombPlace/BombManager/BombManager.h"



class ItemManager
{
public:

	ItemManager();
	~ItemManager();


	void setup();
	void update();
	void draw();

private:

	
	Vec2f block_size;
	BombManager bomb_manager;
	BowManager bow_manager;

};