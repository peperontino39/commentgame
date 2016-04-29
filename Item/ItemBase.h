#pragma once
#include "../Object/MoveObject.h"


class ItemBase : public MoveObject
{
public:

	ItemBase() :
		MoveObject(Vec2f::Zero(), Vec2f::Zero()),
		animation_count(0),
		cut_pos(Vec2f::Zero()),
		cut_size(Vec2f(0.0f, 0.0f)),
		color(Vec3f(0.0f, 0.0f, 0.0f))
	{}
	ItemBase(Vec2f _pos, Vec2f _size, Vec2f vec) :
		MoveObject(_pos, _size),
		animation_count(0),
		cut_pos(Vec2f(0.0f, 0.0f)),
		cut_size(Vec2f(0.0f, 0.0f)),
		color(Vec3f(0.0f, 0.0f, 0.0f))
	{
		vec_ = vec;
	}
	~ItemBase() = default;

	virtual	void update() {};
	virtual	void draw() {};

protected:

	virtual void move() {}

	int animation_count;
	Vec2f cut_pos;
	Vec2f cut_size;
	Vec3f color;

private:

};