#pragma once
#include "../../../Object/Object.h"


class Arrow : public GameObject
{
public:

	Arrow();
	~Arrow();


	void update() override;
	void draw() override;

private:


};