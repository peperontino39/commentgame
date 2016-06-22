#pragma once

#include "../NormalBlock.h"

class Cave : public NormalBlock
{
public:
	Cave(Vec2f, Vec2f);
	void draw() override;

private:

};