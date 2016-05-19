#include "Dummy.h"

Dummy::Dummy(Vec2f _pos, Vec2f _size) :
	BlockBase(_pos, _size)
{



}


void Dummy::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 128, 128,
		Textures::get("dummy"));
}
