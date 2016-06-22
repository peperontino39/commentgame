#include "Slime.h"



Slime::Slime(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{
	std::string pattern("res/Texture/Enemy/slime_pattern.txt");
	std::string action("res/Texture/Enemy/slime_animation.txt");
	readPatterns(pattern);
	readAction(action);

	std::string register_key("slime");
	std::string resourse("res/Texture/Enemy/slimeMotion.png");
	Textures::set(register_key, resourse);
	vec_.x() = 0.5f;
}

Slime::~Slime()
{
}

void Slime::update()
{
	ride_pos = pos + Vec2f(10, size.y());
	ride_size = Vec2f(size.x()-20, 10);
	if (!stan_flag) {
		move();
		fall();
		vector();
		updateChara();
		directionControlEnemy();
	}
	if (stan_flag == true) {
		vec_.x() = 0.0f;
	}
}

void Slime::draw()
{
	if (!blind) {
		drawChara(pos, Textures::get("slime"));
	}
}

void Slime::move()
{
	
}

void Slime::addpos(Vec2f _vec) {

	if (_vec.y() > 0) {
		vec_.y() = 0;
	}
	this->pos += _vec;

	if (_vec.x() > 0) {
		vec_.x() = 0.5;
	}
	if (_vec.x() < 0) {
		vec_.x() = -0.5;
	}
}

void Slime::stan(Vec2f item_pos, Vec2f item_size)
{
	if (collisionBox(pos, size, item_pos, item_size)) {
		stan_flag = true;
	}
	if (stan_flag == true) {
		stan_inc++;
		if (500 >= stan_inc) {
			blind = stan_inc % 2;
		}
		else if (500 <= stan_inc) {
			stan_flag = false;
			stan_inc = 0;
			blind = 0;
			switch (direction)
			{
			case Direction::RIGHT:
				vec_.x() = 0.5f;
				break;
			case Direction::LEFT:
				vec_.x() = -0.5f;
				break;
			}
		}
	}
}


Vec2f Slime::ride(Vec2f player_pos, Vec2f player_size, Vec2f vec)
{
	if (collisionBox(ride_pos, ride_size, player_pos, player_size)) {
		return Vec2f(player_pos.x(), ride_pos.y() + ride_size.y());
	}
	return player_pos;
}



