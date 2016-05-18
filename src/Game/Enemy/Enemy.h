#pragma once
#include "../Object/MoveObject.h"
#include "../CharacterBase/CharacterBase.h"
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
	virtual bool kill(Vec2f player_pos, Vec2f player_size);
	virtual bool attack(Vec2f player_pos, Vec2f player_size);
	
	//WritableP<Vec2f> attack;
protected:
	
	Texture texture;
	float inc;
	bool active;
};





