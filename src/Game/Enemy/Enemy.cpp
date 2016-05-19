#include "Enemy.h"


Enemy::Enemy(Vec2f _pos, Vec2f _size) : 
	CharacterBase(_pos,_size)
{
	
	
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

void Enemy::stan(Vec2f pos,Vec2f size)
{

}

bool Enemy::kill(Vec2f pos, Vec2f size)
{
	return false;
}

bool Enemy::attack(Vec2f pos, Vec2f size)
{
	return false;
}
