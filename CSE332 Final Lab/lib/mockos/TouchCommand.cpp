#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"

TouchCommand::TouchCommand(AbstractFileSystem *fileSystIn, AbstractFileFactory *fileFactIn) : fileSyst(fileSystIn), fileFact(fileFactIn) {}

void TouchCommand::displayInfo() {
    cout << "touch creates a file. To invoke this command, type: 'touch <filename>'" << endl;
    cout << "to create a password protected file, type: 'touch <filename> -p'" << endl;
}

int TouchCommand::execute(std::string argument) {
   if(argument.substr(argument.length()-3, 3) == " -p") {
       argument = argument.substr(0, argument.length()-3);
       AbstractFile *file = fileFact->createFile(argument);
       if (file == nullptr) {
           return FILE_CREATION_ERROR;
       }
       string password;
       cout << "Please enter a one-word password for your file: " << endl;
       cin >> password;
       AbstractFile* pp = new PasswordProxy(file, password);
       int result = fileSyst->addFile(pp->getName(), pp);
       if (result != SUCCESS) {
           delete file;
           delete pp;
           return ADD_FILE_ERR;
       }
       return SUCCESS;
   }
   else {
       argument.erase(std::remove_if(argument.begin(), argument.end(), ::isspace), argument.end());
       AbstractFile *file = fileFact->createFile(argument);
       if (file == nullptr) {
           return FILE_CREATION_ERROR;
       }
       int result = fileSyst->addFile(file->getName(), file);
       if (result != SUCCESS) {
           delete file;
           return ADD_FILE_ERR;
       }
       return SUCCESS;
   }
}