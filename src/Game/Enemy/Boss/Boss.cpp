#include "Boss.h"

Boss::Boss(Vec2f _pos, Vec2f _size) :
	Enemy(_pos, _size)
{
	std::string pattern("res/Texture/Enemy/boss_pattern.txt");
	std::string action("res/Texture/Enemy/boss_animation.txt");
	readPatterns(pattern);
	readAction(action);
	std::string register_key("boss");
	std::string resourse("res/Texture/Enemy/BossMotion.png");
	Textures::set(register_key, resourse);
	vec_.x() = 0.5f;
	attack_count = 0;
	attack_pos = Vec2f::Zero();
	attack_size = Vec2f::Zero();
}

Boss::~Boss()
{
}
void Boss::addpos(Vec2f _vec) {

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
void Boss::update()
{
	if (direction_ == Direction::RIGHT) {
		attack_pos = pos + Vec2f(size.x(), 0.0f);
		attack_size = size;
	}
	if (direction_ == Direction::LEFT) {
		attack_pos = pos + Vec2f(-size.x() / 2, 0.0f);
		attack_size = size;
	}
	if (!stan_flag) {
		move();
		fall();
		vector();
		directionControlEnemy();
	}
	if (stan_flag == true) {
		vec_.x() = 0.0f;
	}
	for (auto& it : fire) {
		it->update();
	}
	for (auto itr = fire.begin(); itr != fire.end(); itr++)
	{
		if ((*itr)->getActive() == false) {
			fire.erase(itr);
			break;
		}
	}
	updateChara();
}

void Boss::draw()
{
	if (!blind) {
		drawChara(pos, Textures::get("boss"));
	}
	for (auto& it : fire) {
		it->draw();
	}
}

void Boss::move()
{
	
}





bool Boss::attack(Vec2f player_pos, Vec2f player_size)
{
	attack_count++;

	if (attack_count == 120) {
		attack_type = random(0, 2);
	}
	if (attack_type == 0) {
		if (attack_count == 120) {
			attack_count = 0;
		}
	}
	breath();
	blade();
	changeDirection(player_pos);



	if (collisionBox(pos, size, player_pos, player_size)) {
		return true;
	}
	for (auto& it : fire) {
		if (collisionBox(it->getPos(), it->getSize(), player_pos, player_size)) {
			return true;
		}
	}
	if (attack_type == 2) {
		if (attack_count >= 150) {
			if (collisionBox(attack_pos, attack_size, player_pos, player_size)) {
				return true;
			}
		}
	}
	return false;
}
void Boss::breath()
{
	if (attack_type == 1) {
		if (attack_count == 120) {
			changeCharaAction(1);
			
		}
		if (attack_count == 150) {
			if (direction_ == Direction::RIGHT) {
				fire.push_back(std::make_shared<Fire>(pos + Vec2f(50, -70), Vec2f(100, 100), direction_));
			}
			if (direction_ == Direction::LEFT) {
				fire.push_back(std::make_shared<Fire>(pos + Vec2f(-130, -70), Vec2f(100, 100), direction_));
			}
			attack_count = 0;
		}
	}
}
void Boss::blade()
{
	if (attack_type == 2) {
		if (attack_count == 120) {
			changeCharaAction(2);
		}
		if (attack_count == 160) {
			attack_count = 0;
		}
	}
}
Vec2f Boss::ride(Vec2f player_pos, Vec2f player_size, Vec2f vec)
{
	return player_pos;
}

void Boss::changeDirection(Vec2f player_pos)
{
	if (pos.x() < player_pos.x()) {
		vec_.x() = 0.5;


	}
	if (pos.x() >= player_pos.x()) {

		vec_.x() = -0.5;
	}
}
