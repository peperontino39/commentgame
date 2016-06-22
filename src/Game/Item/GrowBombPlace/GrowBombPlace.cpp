#include "GrowBombPlace.h"

GrowBombPlace::GrowBombPlace() :
	ItemBase(),
	max_respawn_time(360),
	respawn_time(0),
	is_here_bomb(false)
{
	Textures::set("GrowBombPlace", "res/Texture/Item/GrowBombPlace.png");
	respawn_time = max_respawn_time;
}

GrowBombPlace::GrowBombPlace(Vec2f pos, Vec2f size) :
	ItemBase(ItemID::GROWBOMBPLACE, pos, size, Vec2f::Zero(), Vec2f::Zero(), Vec2f(128.0f, 64.0f)),
	max_respawn_time(120),
	respawn_time(0),
	is_here_bomb(false)
{
	Textures::set("GrowBombPlace", "res/Texture/Item/GrowBombPlace.png");
	respawn_time = max_respawn_time;
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

	drawTextureBox(getPos().x() - getSize().x() / 2.0f,
		getPos().y() - getSize().y() / 2.0f,
		getSize().x(),
		getSize().y(),
		cut_pos.x(),
		cut_pos.y(),
		cut_size.x(),
		cut_size.y(),
		Textures::get("GrowBombPlace"),
		Color(color.x(), color.y(), color.z()));
}