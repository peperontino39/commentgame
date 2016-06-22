#pragma once

#include "../NormalBlock.h"

class CheckPoint : public BlockBase
{
public:
	CheckPoint(Vec2f, Vec2f);
	void draw() override;
	void update() override;
	void checkPoint() override;

	static Vec2f getRespawn();
	static void setRespawn(Vec2f);

	static bool is_check;

private:
	float angle;
	bool ischeck;
	static Vec2f start_pos;

};