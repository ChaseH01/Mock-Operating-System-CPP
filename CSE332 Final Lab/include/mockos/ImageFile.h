#pragma once

#include "mockos/AbstractFile.h"

using namespace std;

class ImageFile : public AbstractFile {
public:
    ImageFile(string filename);

    vector<char> read() override;
    int write(vector<char> v) override;
    int append(vector<char> v) override;
    unsigned int getSize() override;
    string getName() override;
    void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* clone(string filename) override;

private:
    vector<char> contents;
    string name;
    char size;
};