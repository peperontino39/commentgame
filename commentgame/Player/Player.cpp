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
	
}

void Player::draw()
{
	drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white);
}

