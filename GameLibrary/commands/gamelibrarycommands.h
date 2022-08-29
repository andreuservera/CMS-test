#pragma once

#include "../gamelibrary.h"

class CmdAddGame : public Command, GameLibrary
{
public:
    CmdAddGame(string&& game_name);
    void Execute() override;

private:
    string game_name_;
};
