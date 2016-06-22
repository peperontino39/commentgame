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
	void dead(Vec2f pos, Vec2f size,bool dead);
	void load(int _stage_num);
	Vec2f player_ride(Vec2f player_pos,Vec2f player_size,Vec2f player_vec);
	void stan(Vec2f item_pos, Vec2f item_size);
	bool player_dead(Vec2f pos, Vec2f size);
	std::vector<std::function<void()>> function;
	std::list<std::shared_ptr<Enemy>> enemy;
	std::list<std::shared_ptr<Enemy>> enemy_list();
private:
	

};
