#include "command.h"
#include "gamelibrarycommands.h"

CmdAddGame::CmdAddGame(string&& game_name)
    : game_name_(game_name)
{

}

void CmdAddGame::Execute()
{
        Game new_game;
        new_game.Create(game_name_);
        GetGames().push_back(new_game);
}