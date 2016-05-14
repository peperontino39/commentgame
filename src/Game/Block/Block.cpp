#include "Block.h"

Vec2f BlockBase::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	
	return Vec2f::Zero();
}

void BlockBase::update()
{

}

void BlockBase::draw()
{
	/*drawBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(),10, Color::white);*/
}

bool BlockBase::isBreak()
{
	return false;
}

void BlockBase::Break()
{
	
}



Vec2f BlockBase::getPos()
{
	return pos;
}

Vec2f BlockBase::getSize()
{
	return size;
}

Vec2f BlockBase::getVec()
{
	return vec_;
}
