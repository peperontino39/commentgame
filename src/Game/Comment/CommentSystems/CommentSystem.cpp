
#include "CommentSystems.h"

#include "../../AppEnv.h"

#include <chrono>

CommentSystems::CommentSystem::CommentSystem( )
{
    member = std::make_shared<CommentSystems::CommentSystem::_m_CommentSystem>( );
}

struct CommentSystems::CommentSystem::_m_CommentSystem
{
    int frame = 0;
    int remarkFrame = 60;
    Random rander;
public:
    CommentSystems::CommentSystem::_m_CommentSystem( ) 
    { 
        rander.setSeed( std::chrono::system_clock::now( ).time_since_epoch( ).count( ) );
    }
};

void CommentSystems::CommentSystem::update( )
{
    member->frame += 1;
}

bool CommentSystems::CommentSystem::remark( )
{
    return member->frame == member->remarkFrame;
}

void CommentSystems::CommentSystem::setRemark( )
{
    member->remarkFrame = member->frame + 60;
}