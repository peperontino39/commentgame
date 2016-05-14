#pragma once
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"

enum ItemID
{
	GROWBOMBPLACE,
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
		is_player_have(is_player_have_),
		is_countdown(is_countdown_),
		is_end(is_end_)
	{
		id = ItemID::NONE;
		is_draw = true;
		is_player_have = false;
		is_end_ = false;
		is_countdown = false;
	}
	ItemBase(int _id, Vec2f _pos, Vec2f _size, Vec2f vec) :
		MoveObject(_pos, _size),
		id(id_),
		is_draw(is_draw_),
		is_player_have(is_player_have_),
		is_countdown(is_countdown_),
		is_end(is_end_)
	{
		this->vec = vec;
		id = _id;
		is_draw = true;
		is_player_have = false;
		is_end_ = false;
		is_countdown = false;
	}
	~ItemBase() = default;

	virtual	void update() {};
	virtual	void draw() {};

	WritableP<bool> is_draw;
	WritableP<bool> is_player_have;
	WritableP<int> id;
	ReadOnlyP<bool> is_end;
	WritableP<bool> is_countdown;

protected:

	int id_;

	bool is_countdown_;
	bool is_player_have_;
	bool is_draw_;
	bool is_end_;

};


bool collision_BlockToBlcok(const Vec2f& pos1, const Vec2f& size1, const Vec2f& pos2, const Vec2f& size2);