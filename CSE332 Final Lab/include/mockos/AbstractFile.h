#pragma once

#include <vector>
#include <iostream>
#include "Constants.h"


using namespace std;

class AbstractFileVisitor;

class AbstractFile {
public:
    virtual vector<char> read() = 0;
    virtual int write(vector<char> v) = 0;
    virtual int append(vector<char> v) = 0;
    virtual unsigned int getSize() = 0;
    virtual string getName() = 0;
    virtual void accept(AbstractFileVisitor* visitor) = 0;
    virtual AbstractFile* clone(string filename) = 0;
    virtual ~AbstractFile() = default;
};