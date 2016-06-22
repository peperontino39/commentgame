#pragma once
#include "../SceneBase/CreateScene.h"
#include "../EnemyHolder/EnemyHolder.h"
#include "../Map/Map.h"
#include "../Ui/Ui.h"
#include "../Player/PlayerManager.h"
#include "../AppEnv.h"
#include "../Easing/easing.h"
#include "../Item/ItemManager/ItemManager.h"
#include "../Comment/Comment.h"
#include "../Comment/CommentWindow/CommentWindow.h"
#include "../Medias/Medias.h"


class GameMain : public SceneBase
{
public:
	GameMain();
	~GameMain();

	void update() override;
	void draw() override;
	void shift() override;

private:
	void enemycollision();
	void itemcollision();


	void bgload(int);

	Map map;
	Ui ui;
	EnemyHolder enemyholder;
	//ItemManager itemmanager;


	Comment comment;

	Vec2f camera_pos;


	Texture bg;
	Media bgm;
};