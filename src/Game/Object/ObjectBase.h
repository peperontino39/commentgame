#pragma once
#include "../AppEnv.h"
#include "../Share/Property/PropertySystem.h"

class ObjectBase
{
public:

	ObjectBase(Vec2f _pos, Vec2f _size) :
		pos(_pos), size(_size),
		pos_(pos),size_(size)
	{

	}
	WritableP<Vec2f> pos_;
	WritableP<Vec2f> size_;
protected:
	Vec2f pos;
	Vec2f size;
};

