#pragma once

#include <iostream>

using namespace std;

class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    virtual int execute(string argument) = 0;
    virtual void displayInfo() = 0;
};