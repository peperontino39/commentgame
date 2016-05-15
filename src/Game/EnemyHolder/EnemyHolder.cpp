#include "EnemyHolder.h"

EnemyHolder::EnemyHolder()
{
	function.push_back([&] {enemy.push_back(std::make_shared<Slime>(Vec2f(0,0), Vec2f(0, 0))); });
	//function.push_back([&] {enemy.push_back(std::make_shared<Skelton>()); });
	//function.push_back([&] {enemy.push_back(std::make_shared<Golem>()); });
	//function.push_back([&] {enemy.push_back(std::make_shared<Boss>()); });
	int type;
	int count;
	count = 5;
	type = 0;
	//infile >> type;
	function[type]();
	std::list<std::shared_ptr<Enemy>>::iterator itr;

	itr = enemy.begin();
	(*itr)->pos_ = Vec2f(0,0);
	(*itr)->size_ = Vec2f(100, 100);
	//(*itr)->pos_ << in_file;
	//(*itr)->size_ << in_file;
	for (int i = 0; i < count; i++) {
		function[type];
		itr++;
		//(*itr)->pos_ << in_file;
		//(*itr)->size_ << in_file;
	}
}

EnemyHolder::~EnemyHolder()
{
}

void EnemyHolder::update()
{
}

void EnemyHolder::draw()
{
	/*for (auto it : enemy) {
		it->draw();
	}*/
}
