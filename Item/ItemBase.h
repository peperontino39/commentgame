#pragma once
#include "../Object/Object.h"


class ItemBase : public GameObject
{
public:

	//g‚Á‚½‚ÌŠÖ”
	virtual void use(Vec2f _pos, Direction _direction) {};
	virtual	void update() {};
	virtual	void draw() {};

private:

};

