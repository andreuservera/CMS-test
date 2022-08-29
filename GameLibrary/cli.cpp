#include "cli.h"

#include <iostream>
#include <memory>
#include "game.h"
#include "commands/gamelibrarycommands.h"

using namespace std;

Cli::Cli() : exit_(0)
{

}

void Cli::Run()
{
    HandleEvents();
}

void Cli::HandleEvents()
{
    game_library_.Initialize();
    cout << "Type help to list available commands..." << endl;

    while (!exit_)
    {
        cout << ">>> ";
        string line;
        getline(cin, line);
        Process(line);
        command_sender_.ExecuteCommand();
    }
}

void Cli::Process(string& line)
{
    string cmd = "";
    string arg = "";
    ParseCliInput(line, cmd, arg);

    if (cmd.compare("exit") == 0)
    {
        command_sender_.SetCommand(make_unique<CmdExit>());
        exit_ = true;
    }
    else if (cmd.compare("help") == 0)
    {
        command_sender_.SetCommand(make_unique<CmdPrintHelp>());
    }
    else if (cmd.compare("addgame") == 0)
    {
        command_sender_.SetCommand(make_unique<CmdAddGame>(std::move(arg)));
    }
    else
    {
        cout << "Unknown command: " << cmd << endl;
    }
}

void Cli::ParseCliInput(string& input, string& cmd, string& arg)
{
    size_t space_pos = input.find(" ");

    cmd = input.substr(0, space_pos);

    if (space_pos != -1)
    {
        arg = input.substr(space_pos + 1, input.back());
    }
    else
    {
        arg = "";
    }
}
