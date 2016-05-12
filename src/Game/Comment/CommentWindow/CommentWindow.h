#pragma once

#include "../../AppEnv.h"

class CommentWindow
{
public:
    static Vec2f pos;
    static Vec2f size;
private:
    static Vec2f pPos;
    static Vec2f pSize;
public:
    static bool isChange();
public:
    static void update();
};