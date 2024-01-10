#pragma once

#include "AbstractFile.h"

using namespace std;

class TextFile : public AbstractFile {
public:
    TextFile(string filename);

    vector<char> read() override;
    int write(vector<char> v) override;
    int append(vector<char> v) override;
    unsigned int getSize() override;
    void accept(AbstractFileVisitor* visitor) override;
    string getName() override;
    AbstractFile* clone(string filename) override;

private:
    vector<char> contents;
    string name;
};