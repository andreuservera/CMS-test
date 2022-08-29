#pragma once

#include <iostream>
#include <memory>

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
    void SetCommand(unique_ptr<Command> cmd)
    {
        this->cmd_ = move(cmd);
    }

    void ExecuteCommand()
    {
        cmd_->Execute();
    }

private:
    unique_ptr<Command> cmd_;
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