#pragma once
#include "../NormalBlock.h"


class Magma : public NormalBlock
{
public:
	Magma(Vec2f, Vec2f);
	void draw() override;
	void update() override;

private:
	int count;
};
