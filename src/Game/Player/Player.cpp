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
	// 画像の読み込み
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

void Player::itemAction()
{
	if (canCharaInput())
	{
		vec_.x() = 0;
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


void Player::bowAction()
{
	if (canCharaInput())
	{
		vec_.x() = 0;
		if (is_bow_have == false)
			is_bow_have = true;
		else
		{
			is_bow_shot = true;
			is_bow_have = false;
		}
	}
}

// 死亡時一回だけ読み込まれる関数
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

// 死亡時常に読まれ続ける関数
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

// キャラの状態の更新
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
	if (is_bow_have)
		charastate = BOW_HAVE;
	if (is_bow_shot)
		charastate = BOW_SHOT;
	if (is_dead_)
		charastate = DEAD;
	if (is_stageclear)
		charastate = CLEAR;

#if 0
	// 死亡仮置き
	if (canCharaInput())
	{
		size.x() = default_size;
		if (env.isPushKey('K'))
		{
			is_dead_ = !is_dead_;
		}
	}



	// ステージクリア仮置き
	if (canCharaInput())
	{
		if (env.isPushKey('C'))
		{
			is_stageclear = !is_stageclear;
		}
	}






#endif

	// 拾って投げる仮置き
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

	if (is_pick_up == true)
		item_count++;
	if (is_throw == true)
		item_count++;


	if (item_count > 10)
	{
		if (is_bow_shot == true)
		{
			is_bow_shot = false;
			item_count = 0;
		}
	}
	if (is_bow_shot)
		item_count++;
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

	readMemosPattern(patterns);
	readMemosAction(action);

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
	animationChange();
	updateChara();
}

void Player::animationDraw()
{
	drawPlayerChara(pos, Textures::get("Player"));
}











