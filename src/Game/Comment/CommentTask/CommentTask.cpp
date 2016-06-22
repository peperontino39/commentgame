#include "CommentTask.h"

#include "../CommentFlowString/CommentFlowString.h"
#include "../CommentOption/CommentOption.h"
#include "../CommentWindow/CommentWindow.h"
#include "../CommnetStackList/CommentStackList.h"
#include "../CommentCommands/CommentCommands.h"
#include "../CommentData/CommentData.h"
#include "../CommentINIWriter/CommentINIWriter.h"

#include <vector>
#include <sstream>

#include "../../AppEnv.h"

using Comments = std::vector<CommentFlowString>;
using Fonts = std::vector<Font>;

struct CommentTask::_m_CommentTask
{
    Comments comments;
    Fonts fonts;
private:
    Font temp = Font( "res/Font/meiryo.ttc" );    // 一回Fontのコンストラクタを呼んでおかないとメモリーアクセス違反になります。理由は知りません。
};

std::shared_ptr<CommentTask::_m_CommentTask> CommentTask::member = std::make_shared<CommentTask::_m_CommentTask>( );

void CommentTask::fontSizeUpdate( )
{
    member->fonts.at( 0 ).size( ( CommentWindow::size.y( ) / CommentOption::lines ) * 0.5f );
    member->fonts.at( 1 ).size( ( CommentWindow::size.y( ) / CommentOption::lines ) * 0.8f );
    member->fonts.at( 2 ).size( ( CommentWindow::size.y( ) / CommentOption::lines ) * 1.0f );
}

void CommentTask::setup( )
{
    member->fonts = { Font( "res/Font/meiryo.ttc" ), Font( "res/Font/meiryo.ttc" ), Font( "res/Font/meiryo.ttc" ) };
    fontSizeUpdate( );
}

void CommentTask::clear( )
{
    member->comments.clear( );
    member->fonts.clear( );
}

void CommentTask::draw( )    //　コメントの描画は上コメ→下コメ→中央コメの順でします。
{
    glPushMatrix( );

    glTranslatef( CommentWindow::pos.x( ), CommentWindow::pos.y( ), 0 );

    for ( auto& obj : member->comments )
    {
        obj.draw( member->fonts );
    }

#ifdef DEBUG
    drawBox( 0, 0, CommentWindow::size.x( ), CommentWindow::size.y( ), 1, Color::red );
    drawLine( CommentWindow::size.x( ) - CommentWindow::size.x( ) * 1.1f, CommentWindow::size.y( ) / 2.0f,
              CommentWindow::size.x( ) * 1.1f, CommentWindow::size.y( ) / 2.0f,
              1, Color::red );
    drawLine( CommentWindow::size.x( ) / 2.0f, CommentWindow::size.y( ) - CommentWindow::size.y( ) * 1.1f,
              CommentWindow::size.x( ) / 2.0f, CommentWindow::size.y( ) * 1.1f,
              1, Color::red );
#endif

    glPopMatrix( );
}

void CommentTask::update( )
{
    //  コメントウィンドウの原点やサイズが変更されたら呼ばれる。
    if ( CommentWindow::isChange( ) )
    {
        //  自分のクラスのfontをサイズ変更
        fontSizeUpdate( );
        //  コメント登録用のスタックを削除
        CommentStackList::clear( );
        //  コメントを登録するときに、y軸の高さを決定しているため、コメントを再登録して完了
        for ( auto& obj : member->comments ) obj.regist( );
    }

    for ( auto itr = member->comments.begin( ); itr != member->comments.end( );)
    {
        itr->update( );
        if ( !itr->isActive( ) )
        {
            itr = member->comments.erase( itr );
            continue;
        }
        else
        {
            ++itr;
            continue;
        }
    }
}

void CommentTask::create( const std::string & comment, const CommentFlowString::Size size, const CommentFlowString::Type type, const Color & col )
{
    member->comments.push_back( CommentFlowString( comment, size, type, col ) );
}

void CommentTask::create( const CommentStructure& commentData )
{
    std::string comment, size, type, color;
    comment = commentData.comment;
    size = commentData.size == "" ? "normal" : commentData.size;
    type = commentData.type == "" ? "middle" : commentData.type;
    color = commentData.color == "" ? "white" : commentData.color;

    create( comment,
            static_cast< CommentFlowString::Size >( CommentCommands::findSize( size ) ),
            static_cast< CommentFlowString::Type >( CommentCommands::findType( type ) ),
            CommentCommands::findColor( color ) );
}

void CommentTask::create( const std::string & comment )
{
    create( CommentData::find( comment ) );
}
