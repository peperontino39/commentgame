#include "Lift.h"

Lift::Lift(Vec2f _pos, Vec2f _size, int _floor_size, Vec2i _move_sell) :
	NormalBlock(_pos+ Vec2f(_size.x()/2 * (_floor_size-1),0), Vec2f(_size.x()*_floor_size, _size.y()))
{
	move_sell = _move_sell;
	move_end = false;
	bigin_pos = pos;
}

void Lift::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 128, 128,
		Textures::get("rifuto"));
	ago_flame_pos = pos;
}

void Lift::update()
{
	if (!move_end) {
		Easing::Start(pos.x(), bigin_pos.x() +size.x()*move_sell.x(), Easing::Function::QuadInOut,300);
		Easing::Start(pos.y(), bigin_pos.y() + size.y()*move_sell.y(), Easing::Function::QuadInOut,300);
		if (Easing::BeginSet(pos.x())) {
			Easing::BeginSet(pos.y());
			move_end = !move_end;
		}
	}
	else
	{
		Easing::Start(pos.x(), bigin_pos.x(), Easing::Function::QuadInOut,300);
		Easing::Start(pos.y(), bigin_pos.y(), Easing::Function::QuadInOut,300);
		if (Easing::BeginSet(pos.x())) {
			Easing::BeginSet(pos.y());
			move_end = !move_end;
		}
	}
	


}

void Lift::addpos(Vec2f)
{
}

Vec2f Lift::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	
	if (is_hit(pos, size, _pos, _size)) {
		//��
		//if (_vec.y() < 0) {

			if (_pos.y() > (pos.y() + size.y() / 2 + _size.y() / 2) - 21) {
				return Vec2f(0, (pos.y() + size.y() / 2 + _size.y() / 2) - _pos.y()) - getVec();
			}
		//}
		//��
		if (_vec.x() > 0) {
			if (_pos.x() < pos.x()) {
				return Vec2f(pos.x() - size.x() / 2 - _size.x() / 2 - _pos.x(), 0);
			}
		}
		//�E
		if (_vec.x() < 0) {
			if (_pos.x() > pos.x()) {
				return Vec2f(pos.x() + size.x() / 2 + _size.x() / 2 - _pos.x(), 0);
			}
		}
	}
	return Vec2f::Zero();
}

Vec2f Lift::getVec()
{
	return ago_flame_pos - pos;
}

