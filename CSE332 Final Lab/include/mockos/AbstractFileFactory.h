#pragma once

#include <vector>
#include <iostream>
#include "Constants.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

class AbstractFileFactory {
public:
    virtual AbstractFile* createFile(string filename) = 0;
};
