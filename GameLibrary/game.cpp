#include <fstream>
#include <algorithm>
#include "game.h"
#include "pugixml.hpp"

namespace fs = std::filesystem;
static std::string Spaces2Underscores(std::string);

Game::Game()
{
    std::cout << "New game object" << std::endl;
}

void Game::Create(fs::path library_path, std::string name)
{
    name_ = Spaces2Underscores(name);
    library_path_ = library_path;
    time_played_.zero();

    InitializeXML();
}

void Game::InitializeXML()
{
    pugi::xml_document doc;
    pugi::xml_node node = doc.append_child("game");
    pugi::xml_node name = node.append_child("name");
    name.append_child(pugi::node_pcdata).set_value(name_.c_str());

    pugi::xml_node played_time = node.insert_child_after("time-played", name);

    played_time.append_attribute("value") = static_cast<double>(time_played_.count());
    played_time.append_attribute("type")  = "double";

    std::string fileName = name_;
    fileName.append(".xml");

    fs::path path = library_path_;
    path /= fileName;

    fs::create_directories(path.parent_path());

    std::ofstream ofs(path);
    doc.print(ofs);
    ofs.close();
}

std::string Game::GetName()
{
    return name_;
}

static std::string Spaces2Underscores(std::string text)
{
    std::replace(text.begin(), text.end(), ' ', '_');
    return text;
}