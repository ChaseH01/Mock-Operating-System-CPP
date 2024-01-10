#pragma once

#include "AbstractParsingStrategy.h"

using namespace std;

class CreationParsingStrategy : public AbstractParsingStrategy {
public:
    vector<string> parse(string strategy) override;
};