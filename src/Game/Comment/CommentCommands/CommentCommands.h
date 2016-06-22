#pragma once

#include <memory>
#include <string>

#include "../../AppEnv.h"

class CommentCommands
{
    struct _m_CommentDataMap;
    std::shared_ptr<_m_CommentDataMap> member;
private:
    CommentCommands( );
    static CommentCommands& Geti( );
private:
    static Color html( const std::string& str );
public:
    static const size_t findType( const std::string& type );
    static const size_t findSize( const std::string& size );
    static const Color findColor( const std::string& color );
    static const std::string findCommandName( const std::string& command);
};