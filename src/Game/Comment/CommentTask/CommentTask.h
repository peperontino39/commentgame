#pragma once

#include <memory>
#include "../../AppEnv.h"

#include "../CommentFlowString/CommentFlowString.h"
#include "../CommentStructure/CommentStructure.hpp"

class CommentTask
{
    struct _m_CommentTask;
    static std::shared_ptr<_m_CommentTask> member;
public:
    static void fontSizeUpdate( );
public:
    static void setup( );
    static void clear( );
    static void draw( );
    static void update( );
public:
    static void create( const std::string& comment,
                        const CommentFlowString::Size size,
                        const CommentFlowString::Type type,
                        const Color& col );
    static void create( const CommentStructure& commentData );
    static void create( const std::string& behavior );
};