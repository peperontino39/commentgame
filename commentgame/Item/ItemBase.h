#pragma once
#include "../AppEnv.h"


class ItemBase
{
public:
	//g‚Á‚½‚ÌŠÖ”
	virtual void use(Vec2f _pos, Direction _direction) {};
	virtual	void update() {};
	virtual	void draw() {};
private:

};

