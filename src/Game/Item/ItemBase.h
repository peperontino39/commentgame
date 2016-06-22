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
		id(ItemID::NONE),
		is_draw(true),
		is_player_have(false),
		color(Vec3f(1.0f, 1.0f, 1.0f)),
		animation_count(0),
		index(0),
		player_direction(1)
		
	{

	}
	ItemBase(int _id,
		Vec2f _pos,
		Vec2f _size,
		Vec2f vec,
		Vec2f cut_pos,
		Vec2f cut_size) :
		MoveObject(_pos, _size),
		id(_id),
		is_draw(true),
		is_player_have(false),
		cut_pos(cut_pos),
		cut_size(cut_size),
		color(Vec3f(1.0f, 1.0f, 1.0f)),
		animation_count(0),
		index(0),
		player_direction(-1)
	{
		
	}
	~ItemBase() = default;

	int getID() const { return id; }
	bool getIsPlayerHave() const { return is_player_have; }
	void setIsPlayerHave(bool is_player_have) { this->is_player_have = is_player_have; }
	bool getIsDraw() const { return is_draw; }
	void setIsDraw(bool is_draw) { this->is_draw = is_draw; }
	void setPlayerDirection(int player_direction) { this->player_direction = player_direction; }

	virtual	void update() {};
	virtual	void draw() {};

protected:

	int id;
	bool is_player_have;
	bool is_draw;
	Vec2f cut_pos;
	Vec2f cut_size;
	Vec3f color;
	int animation_count;
	int index;
	int player_direction;

};


bool collision_BlockToBlcok(const Vec2f& pos1, const Vec2f& size1, const Vec2f& pos2, const Vec2f& size2);