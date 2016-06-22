#include "CommentData.h"

#include "../CommentINIReader/CommentINIReader.h"

struct CommentData::_m_CommentData
{
    CommentINIReader callFunction;
    std::map<std::string, CommentINIReader> INIData;
};

CommentData::CommentData( )
{
    member = std::make_shared<CommentData::_m_CommentData>( );

    member->callFunction.read( "src/Game/Comment/DataBase/CallFunction.ini" );

    auto& path = member->callFunction.findField( "CallFunction" )["path"];

    auto& data = member->callFunction.data( );

    for ( auto itr = ++data.begin( ); itr != data.end( ); ++itr )
    {
        member->INIData[itr->first].read( path + itr->second["path"] );
    }
}

CommentData & CommentData::Geti( )
{
    static CommentData instans;
    return instans;
}

CommentStructure CommentData::find( const std::string& behavior )
{
    return Geti( ).member->INIData[behavior].randomComment( );
}
