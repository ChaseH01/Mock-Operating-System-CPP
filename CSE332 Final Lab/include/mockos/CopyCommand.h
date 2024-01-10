#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CopyCommand : public AbstractCommand {
public:
    CopyCommand(AbstractFileSystem* fileSystIn);
    ~CopyCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
private:
    AbstractFileSystem* fileSyst;
};