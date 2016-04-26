#pragma once
#include "../Object/MoveObject.h"


class ItemBase : public MoveObject
{
public:

	ItemBase() :
		MoveObject(Vec2f::Zero(), Vec2f::Zero()) {}
	ItemBase(Vec2f _pos, Vec2f _size) :
		MoveObject(_pos, _size) {}
	~ItemBase() = default;

	virtual	void update() {};
	virtual	void draw() {};

private:

};

