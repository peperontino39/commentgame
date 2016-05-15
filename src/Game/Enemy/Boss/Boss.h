#pragma once
#include "../Enemy.h"
class Boss : public Enemy
{
public:
	void update() override;
	void draw() override;
	void stan(Vec2f pos, Vec2f size) override;

private:

};