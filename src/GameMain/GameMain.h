#pragma once
#include "../SceneBase/CreateScene.h"
#include "../Comment/Comment.h"
#include "../EnemyHolder/EnemyHolder.h"
#include "../Map/Map.h"
#include "../Ui/Ui.h"
#include "../Player/PlayerManager.h"
#include "../AppEnv.h"

class GameMain : public SceneBase
{
public:
	GameMain();
	void update() override;
	void draw() override;
	void shift() override;

private:
	
	Map map;
	Ui ui;
	EnemyHolder enemyholder;
	Comment comment;
	Vec2f camera_pos;
};