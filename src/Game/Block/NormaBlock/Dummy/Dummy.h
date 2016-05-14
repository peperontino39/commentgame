#pragma once
#include "../NormalBlock.h"



class Dummy : public NormalBlock
{
public:

	Dummy(Vec2f, Vec2f);

	void draw() override;

private:

};