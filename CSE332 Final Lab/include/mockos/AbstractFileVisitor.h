#pragma once

#include "ImageFile.h"
#include "TextFile.h"

using namespace std;

class AbstractFileVisitor {
public:
    virtual ~AbstractFileVisitor() = default;
    virtual void visit_ImageFile(ImageFile* img) = 0;
    virtual void visit_TextFile(TextFile* txt) = 0;
};