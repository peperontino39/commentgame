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
	std::vector<std::function<void()>> function;
	std::list<std::shared_ptr<Enemy>> enemy;
private:
	
};
