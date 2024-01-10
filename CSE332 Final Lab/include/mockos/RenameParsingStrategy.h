#pragma once

#include "AbstractParsingStrategy.h"

using namespace std;

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
    vector<string> parse(string strategy) override;
};