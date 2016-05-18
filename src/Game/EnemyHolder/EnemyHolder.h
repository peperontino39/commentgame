#pragma once

#include "../AppEnv.h"
#include "../Enemy/Enemy.h"
#include "../Enemy/Boss/Boss.h"
#include "../Enemy/Golem/Golem.h"
#include "../Enemy/Skelton/Skelton.h"
#include "../Enemy/Slime/Slime.h"

class EnemyHolder
{
public:
	EnemyHolder();
	~EnemyHolder();
	void update();
	void draw();
	void playerGetFunction(Vec2f pos, Vec2f size);
	void load(int _stage_num);
	std::list<std::shared_ptr<Enemy>> enemy_list();
	std::vector<std::function<void()>> function;
	std::list<std::shared_ptr<Enemy>> enemy;
	
private:
	bool dead_flag;

};
