#include "mockos/BasicDisplayVisitor.h"
#include "mockos/DisplayCommand.h"

DisplayCommand::DisplayCommand(AbstractFileSystem *fileSystIn) : fileSyst(fileSystIn) {}

void DisplayCommand::displayInfo(){
    cout << "ds opens a file and displays its formatted contents. To invoke this command, type: 'ds <filename>'" << endl;
    cout <<"'ds -d' opens a file and displays its un-formatted contents. To invoke this command, type: 'ds <filename> -d'" <<endl;
}

int DisplayCommand::execute(string argument){
    if(argument.length() > 3 && argument.substr(argument.length()-3, 3) == " -d") {
        argument = argument.substr(0, argument.length() - 3);
        AbstractFile *file = fileSyst->openFile(argument);
        if (file == nullptr) {
            return FILE_DNE_ERR;
        }
        vector<char> bytes = file->read();
        for (char c: bytes) {
            cout << c;
        }
        fileSyst->closeFile(file);
        return SUCCESS;
    }
    argument.erase(std::remove_if(argument.begin(), argument.end(), ::isspace), argument.end());
    AbstractFileVisitor* basicVisitor =  new BasicDisplayVisitor();
    AbstractFile *filePtr = fileSyst->openFile(argument);
    if(filePtr == nullptr){
        return FILE_DNE_ERR;
    }
    filePtr->accept(basicVisitor);
    fileSyst->closeFile(filePtr);
    delete basicVisitor;
    return SUCCESS;
}