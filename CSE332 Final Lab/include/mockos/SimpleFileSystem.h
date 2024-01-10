#pragma once
#include "iostream"
#include "mockos/AbstractFileSystem.h"
#include <set>
#include <map>
#include "Constants.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
private:
    map<string, AbstractFile *> files;
    set<AbstractFile*> openFiles;
public:
    int addFile(string filename, AbstractFile *abFiPtr) override;
    AbstractFile * openFile(string filename) override;
    int closeFile(AbstractFile *abFiPtr) override;
    int deleteFile(string filename) override;
    set<string> getFileNames() override;
};