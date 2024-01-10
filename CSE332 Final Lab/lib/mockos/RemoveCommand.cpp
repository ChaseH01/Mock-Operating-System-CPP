#include "mockos/RemoveCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
#include <iomanip>

RemoveCommand::RemoveCommand(AbstractFileSystem *fileSystIn) : fileSyst(fileSystIn) {}

void RemoveCommand::displayInfo(){
    cout << "rm removes a file from the file system. To invoke this command, type: 'rm <filename>'" << endl;
}

int RemoveCommand::execute(string argument){
    argument.erase(std::remove_if(argument.begin(), argument.end(), ::isspace), argument.end());
    return fileSyst->deleteFile(argument);
}