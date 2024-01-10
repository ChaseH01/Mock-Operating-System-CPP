#pragma once

#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include <map>

using namespace std;

class CommandPrompt {
public:
    CommandPrompt();
    ~CommandPrompt() = default;
    void setFileSystem(AbstractFileSystem* fileSyst);
    void setFileFactory(AbstractFileFactory* fileFact);
    int addCommand(string, AbstractCommand* command);
    int run();
protected:
    void listCommands();
    string prompt();
private:
    map<string, AbstractCommand*> commands;
    AbstractFileSystem* fileSyst;
    AbstractFileFactory* fileFact;
};