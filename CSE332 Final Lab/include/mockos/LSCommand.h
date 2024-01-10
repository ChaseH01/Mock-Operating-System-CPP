#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class LSCommand : public AbstractCommand {
public:
    LSCommand(AbstractFileSystem* fileSystIn);
    ~LSCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
private:
    AbstractFileSystem* fileSyst;
};