#pragma once

#include "../NormalBlock.h"

class Sand : public NormalBlock
{
public:
	Sand(Vec2f, Vec2f);
	void draw() override;
	bool isBreak() override { return true; };

private:

};