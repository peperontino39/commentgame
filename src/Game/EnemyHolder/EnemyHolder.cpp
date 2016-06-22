#include "EnemyHolder.h"

EnemyHolder::EnemyHolder()
{


}

EnemyHolder::~EnemyHolder()
{
}

void EnemyHolder::update() {

	for (auto it : enemy) {
		it->isDead();
		if (it->isDead() == false) {
			it->update();
		}
	}
	for (auto itr = enemy.begin(); itr != enemy.end(); itr++)
	{
		if ((*itr)->getArrive() == false) {
			enemy.erase(itr);
			break;
		}
	}
}

void EnemyHolder::draw()
{
	for (auto it : enemy) {
		it->draw();
	}
}

void EnemyHolder::dead(Vec2f pos, Vec2f size, bool dead)
{
	for (auto it : enemy) {
		it->kill(pos, size);
		it->kill(dead);
	}
}

void EnemyHolder::load(int _stage_num)
{
	std::ifstream file("res/stage/stage" +
		std::to_string(_stage_num) +
		"/Enemy.txt");
	assert(file);

	function.push_back([&] {enemy.push_back(std::make_shared<Slime>(Vec2f(0, 0), Vec2f(0, 0))); });
	function.push_back([&] {enemy.push_back(std::make_shared<Skelton>(Vec2f(0, 0), Vec2f(0, 0))); });
	function.push_back([&] {enemy.push_back(std::make_shared<Golem>(Vec2f(0, 0), Vec2f(0, 0))); });
	function.push_back([&] {enemy.push_back(std::make_shared<Boss>(Vec2f(0, 0), Vec2f(0, 0))); });

	int count;

	file >> count;
	if (1 < count) {
		int type;
		file >> type;

		function[type]();

		std::list<std::shared_ptr<Enemy>>::iterator itr;
		itr = enemy.begin();

		Vec2f pos;
		Vec2f size;

		file >> pos.x();
		file >> pos.y();

		file >> size.x();
		file >> size.y();

		(*itr)->pos_ = pos;
		(*itr)->size_ = size;

		if (2 <= count) {

			for (int i = 0; i < count - 1; i++) {

				int type;
				file >> type;
				function[type]();
				itr++;

				Vec2f pos;
				Vec2f size;

				file >> pos.x();
				file >> pos.y();

				file >> size.x();
				file >> size.y();

				(*itr)->pos_ = pos;
				(*itr)->size_ = size;

			}
		}
	}
}

Vec2f EnemyHolder::player_ride(Vec2f player_pos, Vec2f player_size, Vec2f player_vec)
{
	for (auto it : enemy) {
		return it->ride(player_pos, player_size, player_vec);
	}

}



void EnemyHolder::stan(Vec2f item_pos, Vec2f item_size)
{
	for (auto it : enemy) {
		for (auto it : enemy) {
			it->stan(item_pos, item_size);
		}
	}

}

bool EnemyHolder::player_dead(Vec2f pos, Vec2f size)
{
	for (auto it : enemy) {
		if (it->attack(pos, size) == true) {
			return true;
		}
	}
	return false;
}

std::list<std::shared_ptr<Enemy>> EnemyHolder::enemy_list()
{
	return enemy;
}


