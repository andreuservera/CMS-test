#include "cli.h"

#include <iostream>
#include "game.h"

Cli::Cli() : exit_(0)
{
}

void Cli::Run()
{
    HandleEvents();
}

void Cli::PrintHelp()
{
    std::cout << std::endl;
    std::cout << "Commands: "<< std::endl;
    std::cout << "\t" << "addgame <gamename>" << std::endl
        << "\t" << "deletegame <gamename>" << std::endl
        << "\t" << "playgame <gamename>" << std::endl
        << "\t" << "list" << std::endl << std::endl;
}

void Cli::HandleEvents()
{
    game_library_.Run();
    std::cout << "Type help to list available commands..." << std::endl;

    while (!exit_)
    {
        std::cout << ">>> ";
        std::string line;
        std::getline(std::cin, line);
        Process(line);
    }
}

void Cli::Process(std::string cmd)
{
    if (cmd.compare("exit") == 0)
    {
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
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}
