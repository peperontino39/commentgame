#pragma once
#include "../Object/MoveObject.h"
#include "../CharacterBase/CharacterBase.h"
class _Random
{
public:
	static Random& get()
	{
		static Random rand;
		return rand;
	}
};
#define random _Random::get()
static bool collisionBox(Vec2f pos1, Vec2f size1, Vec2f pos2, Vec2f size2) {
	if (pos1.x() < pos2.x() + size2.x()) {
		if (pos1.x() + size1.x() > pos2.x()) {
			if (pos1.y() < pos2.y() + size2.y()) {
				if (pos1.y() + size1.y() > pos2.y()) {
					return true;
				}
			}
		}
	}
	return false;
}
class Enemy : public CharacterBase
{
public:
	Enemy();
	Enemy(Vec2f _pos, Vec2f _size);
	~Enemy();
	void update() override;
	void draw() override;
	virtual void move();
	virtual void stan(Vec2f item_pos, Vec2f item_size);
	void kill(Vec2f player_pos, Vec2f player_size);
	void kill(bool flag);
	bool isDead();
	const bool& getArrive() {
		return active;
	}
	virtual bool attack(Vec2f player_pos, Vec2f player_size);
	virtual Vec2f ride(Vec2f player_pos, Vec2f player_size, Vec2f vec) = 0;
	
protected:
	
	bool stan_flag;
	bool active;
	bool dead;
	int stan_inc;
	int dead_inc;
	int blind;
	Vec2f dead_pos;
};





