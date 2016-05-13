#pragma once
#include "../Bow.h"
#include "../Arrow/Arrow.h"
#include "../../../Player/PlayerManager.h"



class BowManager
{
public:

	BowManager();
	~BowManager();

	std::list<Arrow>& getArrrow() { return arrows; }

	void deleteitem();

	void setup(Vec2f pos, Vec2f size);
	void update();
	void draw();

private:

	void createArrow();
	void deleteArrow();
	void pickUpBow();
	void putDownBow();

	std::list<Bow> bows;
	std::list<Arrow> arrows;

	//ñÓÇÃï`é ÇÃå¿äEêî
	int max_arrow_draw_num;

};