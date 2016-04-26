#pragma once
#include "ObjectBase.h"
#include "../AppEnv.h"

class MoveObject :public ObjectBase
{
public:
	MoveObject(Vec2f _pos, Vec2f _size) :
		ObjectBase(_pos, _size)
	{

	};
	virtual void draw() = 0;
	virtual void update() = 0;

};