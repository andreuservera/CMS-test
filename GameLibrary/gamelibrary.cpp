#include "gamelibrary.h"
#include "pugixml.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <wordexp.h>

#include "../utils/utils.h"

namespace fs = std::filesystem;


const std::string cLibraryName = "MyGameLibrary";


GameLibrary::GameLibrary()
{
    SetRootDir();
}

void GameLibrary::SetRootDir()
{
    root_dir_ = Utils::GetHomeFolder() + "/" + cLibraryName;
}


void GameLibrary::Initialize()
{
    bool main_folder_exists = CheckForMainFolder();
    if (!main_folder_exists)
    {
        CreateMainFolder();
    }
    else
    {
        std::cout << "Main folder at: " << root_dir_ << "\n";
    }
}

void GameLibrary::CreateMainFolder()
{
    fs::create_directory(root_dir_);
    std::cout << "Main folder created at: " << root_dir_ << "\n";
}

bool GameLibrary::CheckForMainFolder()
{
    return fs::exists(root_dir_);
}

void GameLibrary::AddGame(Game game)
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

