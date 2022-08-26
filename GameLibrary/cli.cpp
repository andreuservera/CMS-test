#include "cli.h"

#include <iostream>
#include "game.h"

using namespace std;

Cli::Cli() : exit_(0)
{

}

void Cli::Run()
{
    HandleEvents();
}

void Cli::PrintHelp()
{
    cout << endl;
    cout << "Commands: "<< endl;
    cout << "\t" << "addgame <gamename>" << endl
        << "\t" << "deletegame <gamename>" << endl
        << "\t" << "playgame <gamename>" << endl
        << "\t" << "list" << endl << endl;
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
        command_sender_.SetCommand(new CmdExit);
        exit_ = true;
    }
    else if (cmd.compare("help") == 0)
    {
        PrintHelp();
    }
    else if (cmd.compare("addgame") == 0)
    {
        Game game;
        game.Create("some_name");
        game_library_.AddGame(game);
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
