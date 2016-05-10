#pragma once
#include "../AppEnv.h"

class Textures
{
public:
	//�摜�̎��ʎq
	//�摜�̃p�X�i�Q�Ɛ�j
	static void set(std::string _path, std::string _texturename) {

		if (t.find(_path) == t.end()) {
			t[_path] = Texture(_texturename);
		}

	}
	//�摜�̎��ʎq
	static Texture get(std::string _path) {

		return t[_path];
	}

private:
	static std::unordered_map<std::string, Texture> t;
};