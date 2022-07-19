#include <iostream>
#include <fstream>

#include "gamelibrary.h"
#include "pugixml.hpp"

namespace fs = std::filesystem;

GameLibrary::GameLibrary()
{
    rootDir_ = fs::path{"/home/andreu/Documents/repos/CommonManagementSolutions/"};
}

void GameLibrary::Run()
{
    std::string library_name = "MyGameLibrary";
    std::cout << "Current Directory: " << rootDir_ << std::endl;
    CreateLibrary(library_name);

    Game game;
    std::string game_name = "Floppy Bird";

    game.Create(rootDir_ / library_name, game_name);
    AddGame(library_name, game);

    game_name = "Minacraft";
    Game game2;
    game2.Create(rootDir_ / library_name, game_name);
    AddGame(library_name, game2);

    ListGames();
}

void GameLibrary::HandleUserInput()
{

}

bool GameLibrary::CreateLibrary(std::string name)
{
    fs::path path{rootDir_};
    path /= name;
    std::cout << "path to library: " << path << std::endl;
    bool result = fs::create_directories(path);
    
    return result;
}

void GameLibrary::AddGame(std::string library_name, Game game)
{
    games_.push_back(game);

    std::cout   << "A game was added to the library: " 
                << game.GetName() 
                << std::endl;
}

void GameLibrary::ListGames()
{
    for (auto it = begin(games_); it != end(games_); it++)
    {
        std::cout << it->GetName() << std::endl;
    }
}