#include "CharacterBase.h"


CharacterBase::CharacterBase(Vec2f _pos, Vec2f _size) :
	MoveObject(_pos, _size),
	gravity(gravity_),
	gravity_max(gravity_max_)
{

}

void CharacterBase::fall()
{
	pos.y() += vec_.y();
	vec_.y() -= gravity_;
}


