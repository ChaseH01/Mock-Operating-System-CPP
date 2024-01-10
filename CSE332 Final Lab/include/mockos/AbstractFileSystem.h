#pragma once
#include <iostream>
#include <set>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
public:
    virtual int addFile(string filename, AbstractFile * abFiPtr) = 0;
    virtual int deleteFile(string filename) = 0;
    virtual AbstractFile * openFile(string filename) = 0;
    virtual int closeFile(AbstractFile * abFiPtr) = 0;
    virtual set<string> getFileNames() = 0;
};