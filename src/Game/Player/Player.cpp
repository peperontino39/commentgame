#include "Player.h"
#include "../Taxture/Taxtures.h"

Player::Player(Vec2f _pos, Vec2f _size) :
	CharacterBase(_pos, _size),
	is_dead(is_dead_)
{
	resourceRoad();
	animationSetup();
}

void Player::resourceRoad()
{
	// ‰æ‘œ‚Ì“Ç‚Ýž‚Ý
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
	directionControl();
	charastateUpdate();
	animationUpdate();
	move();
	fall();
	vector();
}

void Player::draw()
{
	animationDraw();

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
	float speed = 0.2f;
	float stop_speed = 0.5f;
	float speed_max = 3.5f;
	if (canCharaInput())
	{
		if (env.isPressKey('A'))
		{
			vec_.x() -= speed;
			vec_.x() = std::max(vec_.x(), -speed_max);
		}
		else if (env.isPressKey('D'))
		{
			vec_.x() += speed;
			vec_.x() = std::min(vec_.x(), +speed_max);
		}
		else
		{
			if (vec_.x() > 0)
			{
				vec_.x() -= stop_speed;
				vec_.x() = std::max(vec_.x(), 0.0f);
			}
			if (vec_.x() < 0)
			{
				vec_.x() += stop_speed;
				vec_.x() = std::min(vec_.x(), 0.0f);
			}
		}
	}
}

void Player::itemThrowMotion()
{
	if (is_have == true)
	{
		//sizeChange();
	}
}

// Ž€–SŽžˆê‰ñ‚¾‚¯“Ç‚Ýž‚Ü‚ê‚éŠÖ”
void Player::dead()
{
	if (is_dead_ == true)
	{
		float dead_first_speed = 6.0f;
		if (direction_ == Direction::LEFT)
		{
			vec_.x() = -dead_first_speed;
		}
		else
		{
			vec_.x() = dead_first_speed;
		}
		sizeReset();
	}
	else
	{
		size.x() = default_size;
	}

}
void Player::sizeReset()
{
	size.x() = default_size;
	dead_count = 0;

}

// Ž€–SŽží‚É“Ç‚Ü‚ê‘±‚¯‚éŠÖ”
void Player::deadMotion()
{
	if (is_dead_ == true)
	{
		float stop_speed = 0.15f;
		if (vec_.x() > 0)
		{
			vec_.x() -= stop_speed;
			vec_.x() = std::max(vec_.x(), 0.0f);
		}
		if (vec_.x() < 0)
		{
			vec_.x() += stop_speed;
			vec_.x() = std::min(vec_.x(), 0.0f);
		}
		sizeChange();
	}
}

void Player::sizeChange()
{
	if (size_change_timing.find(patterns_size_difference) == size_change_timing.end())
	{
		size_change_timing.clear();
		size_change_timing.insert(patterns_size_difference);

		size.x() += patterns_size_difference;
	}
}

// ƒLƒƒƒ‰‚Ìó‘Ô‚ÌXV
void Player::charastateUpdate()
{
	if (vec_.x() == 0)
		charastate = STOP;
	else
		charastate = WALK;
	if (is_pick_up)
		charastate = BOMB_PICK_UP;
	if (is_have)
		charastate = BOMB_HAVE;
	if (is_throw)
		charastate = BOMB_THROW;
	if (is_dead_)
		charastate = DEAD;

#if 1
	// Ž€–S‰¼’u‚«
	if (canCharaInput())
	{
		size.x() = default_size;
		if (env.isPushKey('K'))
		{
			is_dead_ = !is_dead_;
		}
	}

	// E‚Á‚Ä“Š‚°‚é‰¼’u‚«
	if (canCharaInput())
	{
		if (item_count > 10)
		{
			if (is_pick_up == true)
			{
				is_pick_up = false;
				is_have = true;
				item_count = 0;
			}
			if (is_throw == true)
			{
				is_throw = false;
				item_count = 0;
			}
		}
	}

	if (canCharaInput())
	{
		if (env.isPushKey('I'))
		{
			if (is_have == false)
			{
				is_pick_up = true;
				is_throw = false;
			}
			else
			{
				is_throw = true;
				is_have = false;
			}
		}
	}
	if (is_pick_up == true)
		item_count++;
	if (is_throw == true)
		item_count++;


#endif
}

int Player::getAnimationTime(const std::string name_)
{
	return animation_name.find(name_)->second;
}

void Player::animationChange()
{
	if (now_animation.find(charastate) == now_animation.end())
	{
		now_animation.clear();
		now_animation.insert(charastate);
		changeCharaAction(charastate);

		dead();
		sizeReset();
	}
}

void Player::animationSetup()
{
	std::string patterns("res/Texture/Player/PlayerPattern.txt");
	std::string action("res/Texture/Player/PlayerAction.txt");

	readPatterns(patterns);
	readAction(action);

	std::ifstream animation_name_file("res/Texture/Player/PlayerAnimationName.txt");

	while (!animation_name_file.eof())
	{
		std::string name;
		int num;
		animation_name_file >> name;
		animation_name_file >> num;

		animation_name.insert(std::make_pair(name, num));
	}
}

void Player::animationUpdate()
{
	deadMotion();
	itemThrowMotion();
	animationChange();
	updateChara();
}

void Player::animationDraw()
{
	drawChara(pos, Textures::get("Player"));
}

float Player::getAxis(const std::string& axis_)
{
	int max = 1, min = -1;


	return 0.0f;
}

void Player::axisSetup()
{

}
