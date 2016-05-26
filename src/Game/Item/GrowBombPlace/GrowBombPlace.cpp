#include "GrowBombPlace.h"

GrowBombPlace::GrowBombPlace() :
	ItemBase(),
	max_respawn_time(360),
	respawn_time(0),
	is_here_bomb(false)
{
	/*respawn_time = max_respawn_time;*/
}

GrowBombPlace::GrowBombPlace(Vec2f pos, Vec2f size) :
	ItemBase(ItemID::GROWBOMBPLACE, pos, size, Vec2f::Zero()),
	max_respawn_time(360),
	respawn_time(0),
	is_here_bomb(false)
{
	/*respawn_time = max_respawn_time;*/
}

GrowBombPlace::~GrowBombPlace() {


}

Vec2f GrowBombPlace::createBomb() {

	is_here_bomb = true;

	return getPos();
}

void GrowBombPlace::respawnTime() {

	respawn_time = max_respawn_time;
}


void GrowBombPlace::setup() {

	
}

void GrowBombPlace::update() {

	if (is_here_bomb == false)	
		respawn_time = std::max(respawn_time - 1, 0);
}

void GrowBombPlace::draw() {


}