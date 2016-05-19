#pragma once
#include "../AppEnv.h"


class GameInfo {
public : 
	GameInfo() {
		stage_num;
	};
	static GameInfo& get() {
		static GameInfo _g;
		return _g;

	}

	int stage_num;

};

#define GameInfo GameInfo::get();