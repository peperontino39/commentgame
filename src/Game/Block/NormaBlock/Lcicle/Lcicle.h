#pragma once

#include "../NormalBlock.h"



class Lcicle : public NormalBlock
{
public:

	Lcicle(Vec2f, Vec2f);

	void update() override;
	bool isBreak() override;
	void Break() override;
	void draw() override;
private:
	bool is_fall;
};