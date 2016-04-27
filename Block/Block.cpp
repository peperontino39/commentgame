#include "Block.h"

Vec2f BlockBase::collision(ObjectBase &, Vec2f vec)
{

	return Vec2f::Zero();
}

void BlockBase::update()
{

}

void BlockBase::draw()
{
	drawFillBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), Color::white);

}

Vec2f BlockBase::getPos()
{
	return pos;
}
