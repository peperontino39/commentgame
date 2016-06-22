#pragma once

#include "../../AppEnv.h"

#include <memory>
#include <string>
#include <vector>

class CommentFlowString
{
    struct _m_CommentFlowString;
    std::shared_ptr<_m_CommentFlowString> member;
public:
    enum class Type
    {
        MIDDLE,
        TOP,
        BOTTOM,
    };
    enum class Size
    {
        MIDDLE,
        BIG,
        SMALL,
    };
public:
    CommentFlowString( const std::string& comment,
                       const CommentFlowString::Size size,
                       const CommentFlowString::Type type,
                       const Color& col );
public:
    void draw( std::vector<Font>& font );
    void regist( );
public:
    void update( );
    bool isActive( );
};