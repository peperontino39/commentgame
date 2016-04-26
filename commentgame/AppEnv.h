#pragma once
#include"../lib/framework.hpp"
#include <iostream>
#include <unordered_map>
#include <List>
#include <Vector>

enum Window {
	WIDTH = 1920,
	HEIGHT = 1080
};

enum Direction {
	aLEFT,
	aRIGHT
};


class App
{
public:

	static AppEnv& get() {
		static AppEnv env_(Window::WIDTH, Window::HEIGHT);
		return env_;
	}
private:

};
#define env App::get()





