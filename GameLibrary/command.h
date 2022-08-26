#pragma once

#include <iostream>


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