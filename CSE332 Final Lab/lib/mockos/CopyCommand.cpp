#include "mockos/CopyCommand.h"
#include <string>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem *fileSystIn) : fileSyst(fileSystIn) {}

void CopyCommand::displayInfo(){
    cout << "cp creates a copy of a file and stores it in the filesystem under a new name. To invoke this command, type: 'cp <file_to_copy> <new_name_with_no_extension>'" << endl;
    cout <<"'cat -a' appends input onto existing data. To invoke this command, type: 'cat -a'" <<endl;
}

int CopyCommand::execute(string argument){
    auto positionTxT = argument.find(".txt");
    string currFileName, newFileName;
    if(positionTxT != string::npos) {
        currFileName = argument.substr(0, positionTxT+4);
        newFileName = argument.substr(positionTxT+5);
    }
    auto positionImG = argument.find(".img");
    if(positionImG != string::npos) {
        currFileName = argument.substr(0, positionImG+4);
        newFileName = argument.substr(positionImG+5);
    }
    else if(positionImG == string::npos && positionTxT == string::npos) {
        cout << "Unable to locate the file to copy" << endl;
        return FILE_DNE_ERR;
    }
    AbstractFile* currFile = fileSyst->openFile(currFileName);
    if(currFile == nullptr) {
        return FILE_DNE_ERR;
    }
    AbstractFile* newFile = currFile->clone(newFileName);
    fileSyst->closeFile(currFile);
    int returnVal = fileSyst->addFile(newFile->getName(), newFile);
    if(returnVal != SUCCESS) {
        cout << "Unable to add copy to file system" << endl;
        delete newFile;
    }
    return returnVal;
}