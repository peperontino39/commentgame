#include "Lcicle.h"

Lcicle::Lcicle(Vec2f _pos, Vec2f _size) :
	NormalBlock(_pos, _size)
{

	is_fall = false;
}

void Lcicle::update()
{
	vec_.y() = 0;
	vec_.y() = -is_fall;
	pos += vec_;
}

bool Lcicle::isBreak()
{
	return true;
}

void Lcicle::Break()
{
	is_fall = true;
}


void Lcicle::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 128, 128,
		Textures::get("lcicle"));
}
