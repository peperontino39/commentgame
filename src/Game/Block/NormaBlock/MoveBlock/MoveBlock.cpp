#include "MoveBlock.h"



MoveBlock::MoveBlock(Vec2f _pos, Vec2f _size) :
	NormalBlock(_pos, _size)
{
	pos = _pos;
	size = _size;
	vec = Vec2f(0, 0);

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
				return Vec2f(pos.x() - size.x() / 2 - _size.x() / 2 - _pos.x(), 0);
			}
		}
		//âE
		if (_vec.x() < 0) {
			if (_pos.x() > pos.x()) {
				return Vec2f(pos.x() + size.x() / 2 + _size.x() / 2 - _pos.x(), 0);
			}
		}
	}

	return Vec2f::Zero();
}

void MoveBlock::update()
{
	vec_.y() = std::max(vec_.y() - 0.3f, -20.f);
	pos += vec_;
	
}

void MoveBlock::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0,
		128, 128,
		Textures::get("whiteblock"));
	vec_.x() = 0;
}

void MoveBlock::push(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	if (is_hit(pos, size, _pos, _size)) {
		if (_pos.y() > (pos.y() + size.y() / 2 + _size.y() / 2) - 21) return;
		if (_pos.x() < pos.x()) {
			vec_.x() = -(pos.x() - size.x() / 2 - _size.x() / 2 - _pos.x());

		}
		if (_pos.x() > pos.x()) {
			vec_.x() = -(pos.x() + size.x() / 2 + _size.x() / 2 - _pos.x());

		}
	}
}

void MoveBlock::addpos(Vec2f _vec)
{
	if (_vec.y() > 0) {
		vec_.y() = 0;
	}
	

	this->pos += _vec;
}


