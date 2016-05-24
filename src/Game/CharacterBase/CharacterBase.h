#pragma once
#include "../Object/MoveObject.h"
#include "../Share/Property/PropertySystem.h"

class CharacterBase : public MoveObject {
public:


	CharacterBase(Vec2f _pos, Vec2f _size);

	WritableP<float> gravity;
	WritableP<float> gravity_max;
	ReadOnlyP<Direction> direction;

private:

	float gravity_;
	float gravity_max_;

protected:
	Direction direction_;


protected:
	// posにベクトルを足す
	void vector();
	// 落下
	void fall();
	// xベクトルによって画像を反転させる
	void directionControl();
	void directionControlEnemy();

private:  // アニメーション
	struct Pattern {
		Vec2f offset;
		Vec2f start;
		Vec2f size;
	};
	struct Action {
		std::vector<Vec2i> frame;
		// 次のアクション番号
		int next_action;
		// 硬直時間
		//   入力を受け付けない
		int stiff_time;
	};
	struct Chara {
		// 現在のアクション
		int current_action;
		// アクション経過時間(単位:フレーム)
		int action_time;
		// 現在のフレーム
		int current_frame;
		// 現在のフレームの表示時間(単位:フレーム)
		int frame_time;
	};


	int chara_direction;

	void drawPattern(const Vec2f& pos_,
					 const int& index_,
					 const Texture& tex_);
	void drawAction(const Vec2f& pos_,
					const int& action_index_, const int& frame_index_,
					const Texture& tex_);

	void patternsSizeChangePoint(const int& current_size_);
protected:
	std::vector<Pattern> patterns;
	std::vector<Action> actions;
	Chara chara;
	std::set<int> patterns_sizechange_timing;
	int patterns_size_difference;
	// Charaの初期値変更
	void charaInit(const Chara& chara_);
	// ファイル読み込み
	void readPatterns(const std::string& filename_);
	void readAction(const std::string& filename_);

	// キャラの描画
	void drawChara(const Vec2f& pos_, const Texture& tex_);

	// アニメーションの更新
	void updateChara();
	// キー入力を受け付けるか調べる
	bool canCharaInput();
	// アニメーション変更
	void changeCharaAction(const int& action_index_);


protected:


};