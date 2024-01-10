#include "mockos/CatCommand.h"

CatCommand::CatCommand(AbstractFileSystem *fileSystIn) : fileSyst(fileSystIn) {}

void CatCommand::displayInfo(){
    cout << "cat inputs data that will overwrite your chosen file. To invoke this command, type: 'cat <filename>'" << endl;
    cout <<"'cat -a' appends input onto existing data. To invoke this command, type: 'cat -a'" <<endl;
}

int CatCommand::execute(string argument){
    string userInput;
    if(argument.substr(argument.length()-3, 3) == " -a") {
        argument = argument.substr(0, argument.length()-3);
        if(argument.substr(argument.length()-4, 4) == ".img") {
            return IMG_APPEND_ERR;
        }
        AbstractFile* file = fileSyst->openFile(argument);
        if(file == nullptr) {
            return FILE_DNE_ERR;
        }
        vector<char> bytes = file->read();
        for(char c : bytes) {
            cout << c;
        }
        cout << endl;
        cout << "Enter your input for the file. To save and quit, type ':wq' at the end of your last line, or type ':q' to quit without saving:" << endl;
        while(true) {
            string line;
            getline(cin, line);
            string Qending, WQending;
            if(line.length() >= 2) {
                Qending = line.substr(line.length()-2, 2);
            }
            if(line.length() >= 3) {
                WQending = line.substr(line.length() - 3, 3);
            }
            if(Qending == ":q") {
                fileSyst->closeFile(file);
                return SUCCESS;
            }
            else if(WQending == ":wq") {
                line = line.substr(0,line.length()-3);
                userInput += line;
                vector<char> uI(userInput.begin(), userInput.end());
                file->append(uI);
                fileSyst->closeFile(file);
                return SUCCESS;
            }
            else {
                userInput += line;
            }
        }
    }
    else {
        argument.erase(std::remove_if(argument.begin(), argument.end(), ::isspace), argument.end());
        cout << "Enter your input for the file. To save and quit, type ':wq' at the end of your last line, or type ':q' to quit without saving:" << endl;
        AbstractFile* file = fileSyst->openFile(argument);
        if(file == nullptr) {
            return FILE_DNE_ERR;
        }
        while(true) {
            string line;
            getline(cin, line);
            string Qending, WQending;
            if(line.length() >= 2) {
                Qending = line.substr(line.length()-2, 2);
            }
            if(line.length() >= 3) {
                WQending = line.substr(line.length() - 3, 3);
            }
            if(Qending == ":q") {
                fileSyst->closeFile(file);
                return SUCCESS;
            }
            else if(WQending == ":wq") {
                line = line.substr(0,line.length()-3);
                userInput += line;
                vector<char> uI(userInput.begin(), userInput.end());
                file->write(uI);
                fileSyst->closeFile(file);
                return SUCCESS;
            }
            else {
                userInput += line;
            }
        }
    }
}