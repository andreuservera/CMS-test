#pragma once

#include <filesystem>
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <any>

class Game
{
public:
    Game();
    void Create(std::filesystem::path library_path, std::string name);
    void Update();
    void Parse(std::filesystem::path library_path);
    void PrintAttributes();

    void Play();

    std::string GetName();

private:
    void InitializeXML();


    std::string name_;
    std::filesystem::path library_path_;
    double time_played_;
};