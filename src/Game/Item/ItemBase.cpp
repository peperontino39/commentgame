#include "ItemBase.h"


bool collision_BlockToBlcok(const Vec2f& pos1, const Vec2f& size1, const Vec2f& pos2, const Vec2f& size2) {

	return (pos1.x() + size1.x() >= pos2.x() &&
		pos1.x() <= pos2.x() + size2.x() &&
		pos1.y() + pos1.y() >= pos2.y() &&
		pos1.y() <= pos2.y() + size2.y());
}