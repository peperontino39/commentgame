#pragma once
#include "../AppEnv.h"

class Medias
{
public:
	static void set(std::string _key, std::string _path) {
		if (media.find(_key) == media.end()) {
			media[_key] = std::make_shared<Media>(_path);
		}

	}
	static Media get(std::string _key) {
		return *media[_key];
	}
private:
	static std::unordered_map<std::string, std::shared_ptr<Media>> media;
};