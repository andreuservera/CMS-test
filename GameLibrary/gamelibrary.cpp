#include <iostream>
#include "gamelibrary.h"
#include <filesystem>
#include "pugixml.hpp"

namespace fs = std::filesystem;

GameLibrary::GameLibrary()
{
}

void GameLibrary::Run()
{
    //fs::current_path("/home/andreu/Documents/repos/CommonManagementSolutions");
    std::string library_name = "MyGameLibrary";
    std::cout << fs::current_path() << std::endl;
    CreateLibrary(library_name);
}

void GameLibrary::HandleUserInput()
{

}

void GameLibrary::CreateLibrary(fs::path name)
{
    //fs::path path = "./" + name;
    //fs::create_directory(path);
}

bool GameLibrary::CreateLibrary(std::string name)
{
    //std::string prepend = ".\/";
    //name.insert(0, prepend);
    bool result =  fs::create_directory(name);

    pugi::xml_document doc;
    pugi::xml_node node = doc.append_child("node");

    return result;
}