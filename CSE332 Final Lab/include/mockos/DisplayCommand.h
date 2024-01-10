#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(AbstractFileSystem* fileSystIn);
    ~DisplayCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
private:
    AbstractFileSystem* fileSyst;
};