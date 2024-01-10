#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"
#include <vector>

using namespace std;

class MacroCommand : public AbstractCommand {
public:
    MacroCommand(AbstractFileSystem* fileSystIn);
    ~MacroCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
    int addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* strategy);
private:
    AbstractFileSystem* fileSyst;
    vector<AbstractCommand*> macroCommands;
    AbstractParsingStrategy* strategy;
};