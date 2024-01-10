#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CatCommand : public AbstractCommand {
public:
    CatCommand(AbstractFileSystem* fileSystIn);
    ~CatCommand() = default;
    void displayInfo() override;
    int execute(string argument) override;
private:
    AbstractFileSystem* fileSyst;
};