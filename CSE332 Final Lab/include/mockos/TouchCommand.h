#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
public:
    TouchCommand(AbstractFileSystem* fileSystIn, AbstractFileFactory* fileFactIn);
    ~TouchCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
private:
    AbstractFileSystem* fileSyst;
    AbstractFileFactory* fileFact;
};