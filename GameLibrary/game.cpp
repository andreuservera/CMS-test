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

void Game::Create(std::string name)
{
    name_ = Spaces2Underscores(name);
    time_played_ = 0.0;

    InitializeXML();
    PrintAttributes();
}

static std::string Spaces2Underscores(std::string text)
{
    std::replace(text.begin(), text.end(), ' ', '_');
    return text;
}

void Game::Parse(fs::path library_path)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(library_path.c_str());

    name_ = doc.child("name").value();
    pugi::xml_attribute attr = doc.child("played_time").attribute("value");
    time_played_ = attr.as_double();
}

void Game::InitializeXML()
{
    pugi::xml_document doc;
    pugi::xml_node node = doc.append_child("game");
    pugi::xml_node name = node.append_child("name");
    name.append_child(pugi::node_pcdata).set_value(name_.c_str());

    pugi::xml_node played_time = node.insert_child_after("time-played", name);

    played_time.append_attribute("value") = time_played_;
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

void Game::PrintAttributes()
{
    std::cout << "name: " << name_ << std::endl;
    std::cout << "library: " << library_path_.filename() << std::endl;
    std::cout << "time played: " << time_played_ << std::endl;
}

void Game::SetName(std::string name)
{
    this->name_ = name;
}

std::string Game::GetName()
{
    return name_;
}