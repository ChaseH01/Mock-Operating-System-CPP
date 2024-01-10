#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
public:
    RemoveCommand(AbstractFileSystem* fileSystIn);
    ~RemoveCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
private:
    AbstractFileSystem* fileSyst;
};