#include "CharacterBase.h"


CharacterBase::CharacterBase(Vec2f _pos, Vec2f _size) :
	MoveObject(_pos, _size),
	gravity(gravity_),
	gravity_max(gravity_max_),
	direction(direction_)
{
	chara = { 0,0,0 };
	gravity_ = 0.3f;
	gravity_max_ = 20;
	direction_ = Direction::RIGHT;
	chara_direction = 1;
	patterns_size_difference = 0;
}

void CharacterBase::vector()
{
	pos += vec_;
}

void CharacterBase::fall()
{
	vec_.y() -= gravity_;
	vec_.y() = std::max(vec_.y(), -gravity_max_);
}

void CharacterBase::directionControl()
{
	if (vec_.x() > 0)
	{
		direction_ = Direction::RIGHT;
		chara_direction = 1;
	}
	else if (vec_.x() < 0)
	{
		direction_ = Direction::LEFT;
		chara_direction = -1;
	}
}

void CharacterBase::directionControlEnemy()
{
	if (vec_.x() > 0)
	{
		direction_ = Direction::RIGHT;
		chara_direction = -1;
	}
	else if (vec_.x() < 0)
	{
		direction_ = Direction::LEFT;
		chara_direction = 1;
	}
}

void CharacterBase::readPatterns(const std::string & filename_)
{
	std::ifstream ifs(filename_);
	int count;
	Pattern ptemp;

	while (!ifs.eof())
	{
		ifs >> count;
		for (int i = 0; i < count; i++)
		{
			ifs >> ptemp.offset.x() >> ptemp.offset.y();
			ifs >> ptemp.start.x() >> ptemp.start.y();
			ifs >> ptemp.size.x() >> ptemp.size.y();

			patterns.push_back(ptemp);
		}
	}
}

void CharacterBase::readAction(const std::string & filename_)
{
	std::ifstream ifs(filename_);
	int count;
	Action atemp;

	while (!ifs.eof())
	{
		ifs >> count;
		atemp.frame = std::vector<Vec2i>(count);
		for (int i = 0; i < count; i++)
		{
			ifs >> atemp.frame[i].x() >> atemp.frame[i].y();
		}
		ifs >> atemp.next_action;
		ifs >> atemp.stiff_time;
		actions.push_back(atemp);
	}
}

void CharacterBase::drawPattern(const Vec2f & pos_, const int & index_, const Texture & tex_)
{
	Pattern& p = patterns[index_];
	drawTextureBox(pos_.x() + p.offset.x(), pos_.y() + p.offset.y(),
				   size.x(), size.y(),
				   p.start.x(), p.start.y(),
				   p.size.x(), p.size.y(),
				   tex_, Color::white,
				   0,
				   Vec2f(chara_direction, 1.0f),
				   size / 2);
	patternsSizeChangePoint(p.size.x());
}

void CharacterBase::patternsSizeChangePoint(const int& current_size_)
{
	if (patterns_sizechange_timing.find(current_size_) == patterns_sizechange_timing.end())
	{
		auto past_size = patterns_sizechange_timing.begin();
		if (current_size_ - *past_size > 0)
			patterns_size_difference = current_size_ - *past_size;
		patterns_sizechange_timing.clear();
		patterns_sizechange_timing.insert(current_size_);
	}
}

void CharacterBase::drawAction(const Vec2f & pos_, const int & action_index_, const int & frame_index_, const Texture & tex_)
{
	int pattern_index = actions[action_index_].frame[frame_index_].x();
	drawPattern(pos_, pattern_index, tex_);
}



void CharacterBase::changeCharaAction(const int & action_index_)
{
	chara.current_action = action_index_;
	chara.action_time = 0;
	chara.current_frame = 0;
	chara.frame_time = 0;
}

void CharacterBase::charaInit(const Chara & chara_)
{
	chara = chara_;
}

void CharacterBase::drawChara(const Vec2f & pos_, const Texture & tex_)
{
	drawAction(pos_, chara.current_action, chara.current_frame, tex_);
}

void CharacterBase::updateChara()
{
	chara.action_time += 1;
	chara.frame_time += 1;

	if (chara.frame_time == actions[chara.current_action].frame[chara.current_frame].y()) {
		chara.current_frame += 1;
		chara.frame_time = 0;

		if (chara.current_frame == actions[chara.current_action].frame.size()) {
			changeCharaAction(actions[chara.current_action].next_action);
		}
	}
}

bool CharacterBase::canCharaInput()
{
	return chara.action_time >= actions[chara.current_action].stiff_time;
}


