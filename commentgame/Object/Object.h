#pragma once
#include "ObjectBase.h"
#include "../AppEnv.h"

class GameObject :public Object
{
public:
	GameObject(Vec2f _pos, Vec2f _size) {
		pos = _pos;
		size = _size;
	};
	virtual void draw() = 0;
	virtual void update() = 0;
	
};