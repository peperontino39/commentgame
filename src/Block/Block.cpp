#include "Block.h"

bool is_hit(Vec2f _pos, Vec2f _size, Vec2f floor_pos, Vec2f floor_size) {
	return (_pos.x() > floor_pos.x() - floor_size.x() / 2 - _size.x() / 2 &&
		_pos.x() < floor_pos.x() + floor_size.x() / 2 + _size.x() / 2 &&
		_pos.y() > floor_pos.y() - floor_size.y() / 2 - _size.y() / 2 &&
		_pos.y() < floor_pos.y() + floor_size.y() / 2 + _size.y() / 2
		);
}

Vec2f BlockBase::collision(Vec2f _pos,Vec2f _size, Vec2f _vec)
{
	Vec2f _collision;
	if (is_hit(pos, size, _pos, _size)) {
		//è„
		if (_vec.y() < 0.01) {
			if (up_block) {
				if (_pos.y() > (pos.y() + size.y() / 2 + _size.y() / 2) - 30) {
					return Vec2f(0, (pos.y() + size.y() / 2 + _size.y() / 2) - _pos.y());
				}
			}
		}
		//ç∂
			std::cout << _vec << std::endl;
		if (_vec.x() > 0) {
			if (_pos.x() < pos.x()) {
				return Vec2f(-(_pos.x() + _size.x() / 2) + (pos.x() - size.x() / 2), 0);
			}
		}
		//âE
		if (_vec.x() < 0) {
			if (_pos.x() > pos.x()) {
				return Vec2f((_pos.x() - _size.x() / 2) - (pos.x() + size.x() / 2), 0);
			}
		}


	}
	
	return _vec;
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
