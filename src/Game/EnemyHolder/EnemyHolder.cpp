#include "EnemyHolder.h"

EnemyHolder::EnemyHolder()
{
	dead_flag = false;
	
}

EnemyHolder::~EnemyHolder()
{
}

void EnemyHolder::update(){
	
	for (auto it : enemy) {
		it->update();
	}
}

void EnemyHolder::draw()
{
	for (auto it : enemy) {
		it->draw();
	}
}

void EnemyHolder::playerGetFunction(Vec2f pos, Vec2f size)
{
	for (auto it : enemy) {
		if (it->kill(pos, size)) {
			dead_flag = true;
		}
		
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
			file >> type;
			function[type]();
			itr++;


			for (int i = 0; i < count - 1; i++) {
				if (0 != i) {
					int type;
					file >> type;
					function[type]();
				}
				Vec2f pos;
				Vec2f size;

				file >> pos.x();
				file >> pos.y();

				file >> size.x();
				file >> size.y();

				(*itr)->pos_ = pos;
				(*itr)->size_ = size;
				itr++;
			}
		}
	}
}

std::list<std::shared_ptr<Enemy>> EnemyHolder::enemy_list()
{
	return enemy;
}
