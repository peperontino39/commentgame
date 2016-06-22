#include "Arrow.h"


Arrow::Arrow() :
	ItemBase()
{
	Textures::set("Arrow", "res/Texture/Item/Arrow.png");
}

Arrow::Arrow(Vec2f _pos, Vec2f _size, Vec2f _vec, float rad) :
	ItemBase(ItemID::ARROW,
		_pos,
		_size,
		_vec,
		Vec2f(0.0f, 0.0f),
		Vec2f(128.0f, 64.0f)),
		rad(rad)
{
	Textures::set("Arrow", "res/Texture/Item/Arrow.png");
}

Arrow::~Arrow() {

}

void Arrow::update() {

	move();
}

void Arrow::draw() {
	
	if (player_direction == 1)
	{
		drawTextureBox(pos.x(),
			pos.y() - size.y() / 2 + 32.0f,
			size.x(), size.y(),
			cut_pos.x(),
			cut_pos.y(),
			cut_size.x(),
			cut_size.y(),
			Textures::get("Arrow"),
			Color(color.x(), color.y(), color.z()),
			rad,
			Vec2f(player_direction, 1.0f),
			Vec2f(32.0f, size.x() / 2));
	}
	else if (player_direction == -1)
	{
		drawTextureBox(pos.x() - 23.0f,
			pos.y() - size.y() / 2.0f + 23.0f,
			size.x(),
			size.y(),
			cut_pos.x(),
			cut_pos.y(),
			cut_size.x(),
			cut_size.y(),
			Textures::get("Arrow"),
			Color(color.x(), color.y(), color.z()),
			-rad,
			Vec2f(-1.0f, 1.0f),
			Vec2f(32.0f, size.x() / 2));
	}
}

void Arrow::move() {

	setPos(Vec2f(getPos().x() + getVec().x(), getPos().y() + getVec().y()));
}
