#include "mockos/CreationParsingStrategy.h"
#include <string>

vector<string> CreationParsingStrategy::parse(std::string strategy) {
    vector<string> args = {strategy, strategy};
    return args;
}