#pragma once
#include <string>

using namespace std;

class AbstractParsingStrategy {
public:
    virtual vector<string> parse(string strategy) = 0;
};