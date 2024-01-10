#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
#include <iomanip>
#include <algorithm>

LSCommand::LSCommand(AbstractFileSystem *fileSystIn) : fileSyst(fileSystIn) {}

void LSCommand::displayInfo(){
    cout << "ls displays all the names of the files currently in the file system. To invoke this command, type: 'ls'" << endl;
    cout <<"'ls -m' displays every filename with its associated metadata. To invoke this command, type: 'ls -m'" <<endl;
}

int LSCommand::execute(string argument){
    std::set<std::string> fileNames = fileSyst->getFileNames();
    argument.erase(std::remove_if(argument.begin(), argument.end(), ::isspace), argument.end());
    if(argument == "-m"){
        AbstractFileVisitor* MDvisitor =  new MetadataDisplayVisitor();
        for (auto str : fileNames) {
            AbstractFile *filePtr = fileSyst->openFile(str);
            filePtr->accept(MDvisitor);
            fileSyst->closeFile(filePtr);
        }
        delete MDvisitor;
        return SUCCESS;
    }
    else if(argument == ""){

        int count = 0;
        for (auto str : fileNames) {
            if(count%2 == 0){
                cout << str;
            }
            else {
                cout << setw(20) << str << endl;
            }
            ++count;
        }
        return SUCCESS;
    }
    return LS_ERR;
}