#pragma once

#include <memory>

class CommentSystems
{
public:
    class CommentFeeling
    {
        struct _m_CommentFeeling;
        std::shared_ptr<_m_CommentFeeling> member;
    public:
        CommentFeeling( );
    };
public:
    class CommentSystem
    {
        struct _m_CommentSystem;
        std::shared_ptr<_m_CommentSystem> member;
    public:
        CommentSystem( );
        void update( );
        bool remark( );
        void setRemark( );
    };
};
