#include "mockos/RenameParsingStrategy.h"
#include <string>

vector<string> RenameParsingStrategy::parse(std::string strategy) {
    string firstArg, secondArg;
    auto txtPos = strategy.find(".txt");
    auto imgPos = strategy.find(".img");
    if (txtPos != string::npos) {
        firstArg = strategy.substr(0, txtPos+4);
        secondArg = strategy.substr(txtPos+4);
    }
    else if(imgPos != string::npos){
        firstArg = strategy.substr(0, imgPos+4);
        secondArg = strategy.substr(imgPos+4);
    }
    vector<string> args = {firstArg+secondArg, firstArg};
    return args;
}