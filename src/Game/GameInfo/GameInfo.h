#pragma once
#include "../AppEnv.h"


class GameInformation {
public : 
	GameInformation() {
		stage_num;
	};
	static GameInformation& get() {
		static GameInformation _g;
		return _g;

	}

	int stage_num;

};

#define GameInfo GameInformation::get()