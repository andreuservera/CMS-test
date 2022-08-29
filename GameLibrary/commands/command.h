#pragma once

#include <iostream>

using namespace std;

class Command
{
public:
    virtual ~Command(){};
    virtual void Execute() = 0;
};

class CommandSender
{
public:
    ~CommandSender()
    {
        delete cmd;
    }
    void SetCommand(Command* cmd)
    {
        delete this->cmd;
        this->cmd = cmd;
    }

    void ExecuteCommand()
    {
        cmd->Execute();
    }

private:
    Command *cmd;
};

class CmdExit : public Command
{
    void Execute() override
    {
        std::cout << "EXITING..." << "\n";
    };
};

class CmdPrintHelp : public Command
{
    void Execute() override
    {
        cout << endl;
        cout << "Commands: "<< endl;
        cout << "\t" << "addgame <gamename>" << endl
            << "\t" << "deletegame <gamename>" << endl
            << "\t" << "playgame <gamename>" << endl
            << "\t" << "list" << endl << endl;
    }
};