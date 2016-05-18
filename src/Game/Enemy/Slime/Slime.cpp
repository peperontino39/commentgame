#include "Slime.h"



Slime::Slime(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{
	ride_pos = _pos + Vec2f(0, _size.y());
	ride_size = Vec2f(_size.x(), 10);
}

Slime::~Slime()
{
}

void Slime::update()
{
	move();
	fall();
	vector();
}

void Slime::draw()
{
	drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white,0,Vec2f(1,1),Vec2f(size.x()/2,size.y()/2));
}

void Slime::move()
{
	pos.x()++;
}

void Slime::stan(Vec2f item_pos, Vec2f item_size)
{
}

Vec2f Slime::ride(Vec2f player_pos, Vec2f player_size, Vec2f vec)
{
	if (collisionBox(ride_pos, ride_size, player_pos, player_size)) {
		return vec;
	}
	return vec;
}

bool Slime::kill(Vec2f player_pos, Vec2f player_size)
{
	if (collisionBox(player_pos, player_size, pos, size)) {
		
		return true;
	}
	return false;
}

bool Slime::attack(Vec2f player_pos, Vec2f player_size)
{
	return false;
}
