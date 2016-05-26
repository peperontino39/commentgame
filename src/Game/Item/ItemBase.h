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
		is_countdown(false),
		is_end(false)
	{

	}
	ItemBase(int _id, Vec2f _pos, Vec2f _size, Vec2f vec) :
		MoveObject(_pos, _size),
		id(_id),
		is_draw(true),
		is_player_have(false),
		is_countdown(false),
		is_end(false)
	{
		
	}
	~ItemBase() = default;

	int getID() const { return id; }
	bool getIsCountdown() const { return is_countdown; }
	void setIsCountdown(bool is_countdown) { this->is_countdown = is_countdown; }
	bool getIsPlayerHave() const { return is_player_have; }
	void setIsPlayerHave(bool is_player_have) { this->is_player_have = is_player_have; }
	bool getIsDraw() const { return is_draw; }
	void setIsDraw(bool is_draw) { this->is_draw = is_draw; }
	bool getIsEnd() const { return is_end; }

	virtual	void update() {};
	virtual	void draw() {};

protected:

	int id;
	bool is_countdown;
	bool is_player_have;
	bool is_draw;
	bool is_end;

};


bool collision_BlockToBlcok(const Vec2f& pos1, const Vec2f& size1, const Vec2f& pos2, const Vec2f& size2);