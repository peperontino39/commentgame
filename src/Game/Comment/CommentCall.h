#pragma once

#include "CommentCreater/CommentCreater.h"

//  コメントデータベースから参照してコメントを出力します。
//  データベースに存在しない場合は、デフォルト設定での出力となります。
#define COMCALL( behavior ) CommentCreater::comment( #behavior );

//  コメントデータベースから参照してコメントを出力します。
//  データベースに存在しない場合は、デフォルト設定での出力となります。
void comment( const std::string& behavior );

//  新しくコメントを生成できます。
//  コマンドは順不同なので、好きにお打ちください。
//  コマンドの種類に関しましては、src/Comment/CommentCommands.txtを御覧ください。
void comment( const std::string& comment, const std::string& commandA, const std::string& commandB = "", const std::string& commandC = "" );