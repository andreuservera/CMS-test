#include "gamelibrary.h"
#include "pugixml.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <wordexp.h>

namespace fs = std::filesystem;

const std::string cLibraryName = "MyGameLibrary";
const char * cPathToMainFolder = "$HOME/MyGameLibrary";

GameLibrary::GameLibrary()
{
    SetRootDir();
}

void GameLibrary::SetRootDir()
{
    wordexp_t p;
    char** w;
    wordexp(cPathToMainFolder , &p, 0 );
    w = p.we_wordv;
    root_dir_ = *w;
    wordfree( &p );
}


void GameLibrary::Run()
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

//bool GameLibrary::CreateLibrary()
//{
//    fs::path path{cRootDir};
//    fs::current_path(path);
//    path /= cLibraryName;
//    std::cout << "path to library: " << path << std::endl;
//    bool result = fs::create_directory(path);
//    
//    return result;
//}

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

