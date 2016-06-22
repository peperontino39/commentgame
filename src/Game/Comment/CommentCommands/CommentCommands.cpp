#include "CommentCommands.h"

#include "../CommentINIReader/CommentINIReader.h"

#include "../../Share/Utility/Utility.h"

struct CommentCommands::_m_CommentDataMap
{
    CommentINIReader INIData;
};

CommentCommands::CommentCommands( )
{
    member = std::make_shared<CommentCommands::_m_CommentDataMap>( );
    member->INIData.read( "src/Game/Comment/CommentCommands/CommentCommands.ini" );
}

CommentCommands & CommentCommands::Geti( )
{
    static CommentCommands instans;
    return instans;
}

Color CommentCommands::html( const std::string & str )
{
    if ( str [0] != '#' ) return Color::white;
    if ( str.size( ) != 7 ) return Color::white;

    Color col = Color::white;
    col.r( ) = std::stof( "0X" + str.substr( 1, 2 ) ) / 255.0f;
    col.g( ) = std::stof( "0X" + str.substr( 3, 2 ) ) / 255.0f;
    col.b( ) = std::stof( "0X" + str.substr( 5, 2 ) ) / 255.0f;

    return col;
}

const size_t CommentCommands::findType( const std::string& type )
{
    return std::stoull( Geti( ).member->INIData ["Type"] [type] );
}

const size_t CommentCommands::findSize( const std::string& size )
{
    return std::stoull( Geti( ).member->INIData ["Size"] [size] );
}

const Color CommentCommands::findColor( const std::string & color )
{
    return html( Geti( ).member->INIData ["Color"] [color] );
}

const std::string CommentCommands::findCommandName( const std::string & command )
{
    std::string temp;

    temp = Geti( ).member->INIData ["Type"] [command];
    if ( temp != "" )
    {
        return "Type";
    }

    temp = Geti( ).member->INIData ["Size"] [command];
    if ( temp != "" )
    {
        return "Size";
    }

    temp = Geti( ).member->INIData ["Color"] [command];
    if ( temp != "" )
    {
        return "Color";
    }

    return "";
}
