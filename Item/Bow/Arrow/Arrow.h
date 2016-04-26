#pragma once
#include "../../ItemBase.h"


class Arrow : public ItemBase
{
public:

	Arrow();
	Arrow(Vec2f _pos, Vec2f _size);
	~Arrow();


	void update() override;
	void draw() override;

private:


};