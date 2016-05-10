#pragma once
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"

enum ItemID
{
	BOMB,
	BOW,
	ARROW,
	NONE = 64
};


class ItemBase : public MoveObject
{
public:

	ItemBase() :
		MoveObject(Vec2f::Zero(), Vec2f::Zero()),
		id(id_),
		is_draw(is_draw_),
		is_player_have(is_player_have_)
	{
		id = ItemID::NONE;
		is_draw = true;
		is_player_have = false;
	}
	ItemBase(int _id, Vec2f _pos, Vec2f _size, Vec2f vec) :
		MoveObject(_pos, _size),
		id(id_),
		is_draw(is_draw_),
		is_player_have(is_player_have_)
	{
		this->vec = vec;
		id = _id;
		is_draw = true;
		is_player_have = false;
	}
	~ItemBase() = default;

	virtual	void update() {};
	virtual	void draw() {};

	WritableP<bool> is_draw;
	WritableP<bool> is_player_have;
	WritableP<int> id;

private:

	int id_;

	bool is_player_have_;
	bool is_draw_;

};