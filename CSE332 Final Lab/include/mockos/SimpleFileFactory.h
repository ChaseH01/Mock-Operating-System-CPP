#pragma once

#include <vector>
#include <iostream>
#include "Constants.h"
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
    AbstractFile* createFile(string filename) override;
};