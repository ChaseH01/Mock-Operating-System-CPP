#include "mockos/CommandPrompt.h"

#include <sstream>
#include <iostream>

using namespace std;

CommandPrompt::CommandPrompt() : fileSyst(nullptr), fileFact(nullptr){}

void CommandPrompt::setFileFactory(AbstractFileFactory *fileFactIn) {
    this->fileFact = fileFactIn;
}

void CommandPrompt::setFileSystem(AbstractFileSystem *fileSystIn) {
    this->fileSyst = fileSystIn;
}

int CommandPrompt::addCommand(string str, AbstractCommand* command) {
    if(commands.insert(make_pair(str, command)).second) {
        return SUCCESS;
    }
    return ADD_COMMAND_ERR;
}

void CommandPrompt::listCommands() {
    for(auto& pair : commands) {
        cout << pair.first << endl;
    }
}

string CommandPrompt::prompt() {
    cout << endl;
    cout << "Enter a command, 'q' to quit, 'help' for a list of commands, or\n"
            "help followed by a command name for more information about\n"
            "that command. Ex: 'help <command_name>'" << endl;
    cout << "$  ";

    string response;
    getline(cin, response);
    return response;
}

int CommandPrompt::run() {
    while(true) {
        string userCommand = prompt();
        if(userCommand == "q") {
            return USER_QUIT;
        }
        else if(userCommand == "help") {
            listCommands();
        }
        else if(userCommand.find(' ') == string::npos) { //enters the body if there is not a space: ie - enters the body if its one word
            auto it = commands.find(userCommand);
            if(it == commands.end()) {
                cout << "Invalid Command" << endl;
            }
            else {
                int result = it->second->execute(""); //excute the corresponding command with a space as the argument
                if(result != SUCCESS) {
                    cout << "Error executing command" << endl;
                }
            }
        }
        else {
            istringstream iss(userCommand);

            string firstWord, secondWord, thirdWord;
            iss >> firstWord;
            iss >> secondWord;
            iss >> thirdWord;

            if(firstWord != "help") {
                auto it = commands.find(firstWord);
                if(it == commands.end()) {
                    cout << "Invalid Command" << endl;
                }
                else {
                    int result = commands[firstWord]->execute(secondWord+" "+thirdWord);
                    if(result != SUCCESS) {
                        cout << "Error executing command" << endl;
                    }
                }
            }
            else {
                auto it = commands.find(secondWord);
                if(it == commands.end()) {
                    cout << "Invalid Command" << endl;
                }
                else {
                    it->second->displayInfo();
                }
            }
        }
    }
}