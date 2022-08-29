#pragma once

#include <string>
#include "gamelibrary.h"
#include "commands/command.h"

class Cli
{
public:
    Cli();

    void Run();
    void HandleEvents();

private:
    void Process(std::string& line);
    void ParseCliInput(std::string& input, std::string& cmd, std::string& arg);
    bool exit_;
    CommandSender command_sender_;

    GameLibrary game_library_;
};