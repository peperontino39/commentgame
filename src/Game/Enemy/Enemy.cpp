#include "Enemy.h"


Enemy::Enemy(Vec2f _pos, Vec2f _size) : 
	CharacterBase(_pos,_size)
{
	stan_flag = false;
	active = true;
	stan_inc = 0;
	blind = 0;
	dead = false;
	dead_inc = 0;
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
}

void Enemy::draw()
{
}

void Enemy::move()
{
}

void Enemy::stan(Vec2f item_pos, Vec2f item_size)
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

void Enemy::kill(Vec2f _pos, Vec2f _size)
{
	if (collisionBox(pos, size, _pos, _size)) {
		dead = true;
	}
}

void Enemy::kill(bool flag)
{
	if (flag == true) {
		dead = true;
	}
}

bool Enemy::isDead() {
	if (dead == true) {
		dead_inc++;
		if (dead_inc == 1) {
			dead_pos = pos;
		}
		pos = dead_pos;
		pos += Vec2f(random(-10.0f, 10.0f), 0.0f);
		if (300 <= stan_inc) {
			active = false;
		}
		return true;
	}
	return false;
}

bool Enemy::attack(Vec2f _pos, Vec2f _size)
{
	if (collisionBox(pos, size, _pos, _size)) {
		return true;
	}
	return false;
}


