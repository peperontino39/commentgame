#include "Player.h"
#include "../Taxture/Taxtures.h"

Player::Player(Vec2f _pos, Vec2f _size) :
	CharacterBase(_pos, _size)
{
	resourceRoad();
}
void Player::resourceRoad()
{
	std::string register_key;
	std::string resource;

	std::ifstream player_resource("res/Texture/Player/PlayerTextureResource.txt");

	while (!player_resource.eof())
	{
		player_resource >> register_key;
		player_resource >> resource;

		Textures::set(register_key, resource);
	}
	
}


Player::~Player()
{
}

void Player::update()
{
	move();
	fall();
	vector();
}

void Player::draw()
{
	drawBox(pos.x(), pos.y(), 
			size.x(), size.y(), 
			5, Color::white,
			0,
			Vec2f(1, 1),
			Vec2f(size.x() / 2, size.y() / 2));
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
	float speed_up = 0.3;
	float speed_max = 5;
	vec_.x() = 0.0f;
	if (env.isPressKey('A'))
	{
		vec_.x() -= speed_up;
	}
	if (env.isPressKey('D'))
	{
		vec_.x() += speed_up;
	}
}

void Player::animation()
{



}

