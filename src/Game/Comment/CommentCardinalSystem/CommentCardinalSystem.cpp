#include "CommentCardinalSystem.h"

#include "../CommentCall.h"

#include "../CommentSystems/CommentSystems.h"

struct CommentCardinalSystem::_m_CommentCardinalSystem
{
    CommentSystems::CommentFeeling feelings;
    CommentSystems::CommentSystem systems;
};

std::shared_ptr<CommentCardinalSystem::_m_CommentCardinalSystem> CommentCardinalSystem::member;

void CommentCardinalSystem::setup( )
{
    member = std::make_shared<CommentCardinalSystem::_m_CommentCardinalSystem>( );
}

void CommentCardinalSystem::clear( )
{
    /*nothing*/
}

void CommentCardinalSystem::update( )
{
    member->systems.update( );

    if ( member->systems.remark( ) )
    {
        COMCALL( CommentCardinalSystem );
        member->systems.setRemark( );
    }
}
