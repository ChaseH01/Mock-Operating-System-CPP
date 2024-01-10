#include "mockos/MacroCommand.h"
#include <string>


using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem *fileSystIn) : fileSyst(fileSystIn) {}

void MacroCommand::displayInfo(){
    cout <<"Macrocommands are commands built out of other commands. Here are the two macrocommands: "<< endl;
    cout <<"1. rename copies a file with your desired new name, and then removes the old file. Invoke this command by typing: 'rn <file_to_copy> <new_name_with_no_extensions>'" <<endl;
    cout<<"2. create allows a user to touch and cat on a file all in one. Invoke this command by typing 'cr <new_file_name>'"<<endl;
}

int MacroCommand::execute(string argument) {
    vector<string> parsedArgs = strategy->parse(argument);
    for(size_t i = 0; AbstractCommand* command : macroCommands) {
        int returnVal = command->execute(parsedArgs[i]);
        if(returnVal != SUCCESS) {
            return returnVal;
        }
        ++i;
    }
    return SUCCESS;
}

int MacroCommand::addCommand(AbstractCommand *command) {
    macroCommands.push_back(command);
    return SUCCESS;
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy *strategy) {
    this->strategy = strategy;
}