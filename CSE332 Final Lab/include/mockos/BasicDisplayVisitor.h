#pragma once

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_ImageFile(ImageFile* img) override;
    void visit_TextFile(TextFile* txt) override;
};