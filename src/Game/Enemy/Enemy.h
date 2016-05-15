#pragma once
#include "../Object/MoveObject.h"
#include "../CharacterBase/CharacterBase.h"

class Enemy : public CharacterBase
{
public:
	Enemy();
	Enemy(Vec2f _pos, Vec2f _size);
	~Enemy();
	void update() override;
	void draw() override;
	virtual void stan(Vec2f pos, Vec2f size);
	//WritableP<Vec2f> attack;
protected:
	
	Texture texture;
	int type;
	bool active;
};





