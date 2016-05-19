#include "GrowBombPlace.h"

GrowBombPlace::GrowBombPlace() :
	ItemBase(),
	max_respawn_time(360),
	respawn_time(respawn_time_),
	is_here_bomb(is_here_bomb_)
{
	respawn_time_ = 0;
	/*respawn_time = max_respawn_time;*/
	is_here_bomb_ = false;
}

GrowBombPlace::GrowBombPlace(Vec2f pos, Vec2f size) :
	ItemBase(ItemID::GROWBOMBPLACE, pos, size, Vec2f::Zero()),
	max_respawn_time(360),
	respawn_time(respawn_time_),
	is_here_bomb(is_here_bomb_)
{
	respawn_time_ = 0;
	/*respawn_time = max_respawn_time;*/
	is_here_bomb_ = false;
}

GrowBombPlace::~GrowBombPlace() {


}

Vec2f GrowBombPlace::createBomb() {

	is_here_bomb = true;

	return pos;
}

void GrowBombPlace::respawnTime() {

	respawn_time = max_respawn_time;
}


void GrowBombPlace::setup() {


}

void GrowBombPlace::update() {

	if (is_here_bomb_ == false)	
		respawn_time_ = std::max(respawn_time_ - 1, 0);
}

void GrowBombPlace::draw() {


}