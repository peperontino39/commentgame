#include "MoveBlock.h"

MoveBlock::MoveBlock(Vec2f _pos, Vec2f _size):
	NormalBlock(_pos, _size)
{

}

Vec2f MoveBlock::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	if (is_hit(pos, size, _pos, _size)) {
		//è„
		if (_vec.y() < 0) {

			if (_pos.y() > (pos.y() + size.y() / 2 + _size.y() / 2) - 21) {
				return Vec2f(0, (pos.y() + size.y() / 2 + _size.y() / 2) - _pos.y());
			}
		}
		//ç∂
		if (_vec.x() > 0) {
			if (_pos.x() < pos.x()) {
				pos += Vec2f(pos.x() - size.x() / 2 - _size.x() / 2 - _pos.x(), 0);
				return Vec2f::Zero();
			}
		}
		//âE
		if (_vec.x() < 0) {
			if (_pos.x() > pos.x()) {
				pos += Vec2f(pos.x() + size.x() / 2 + _size.x() / 2 - _pos.x(), 0);
				return Vec2f::Zero();
			}
		}
	}

	return Vec2f::Zero();
}

void MoveBlock::update()
{
	vec.y() = std::max(vec.y() - 0.3f, 20.f);

	pos += vec;

}
