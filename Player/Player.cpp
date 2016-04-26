#include "Player.h"

Player::Player(Vec2f _pos, Vec2f _size) : 
	MoveObject(_pos, _size)
{
}

Player::~Player()
{
}

void Player::update()
{
	move();
}

void Player::draw()
{
	drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white);
}

void Player::setPos(Vec2f _pos)
{
	pos = _pos;
}

void Player::setSize(Vec2f _size)
{
	size = _size;
}

Vec2f Player::getPos()
{
	return pos;
}

Vec2f Player::getSize()
{
	return size;
}

void Player::move()
{
	if (env.isPressKey('A'))
	{
		pos.x() -= 5;
	}
	if (env.isPressKey('D'))
	{
		pos.x() += 5;
	}
}

