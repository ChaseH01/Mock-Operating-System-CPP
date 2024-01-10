#include "mockos/SimpleFileSystem.h"

using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile *abFiPtr) {
    if(files.count(filename) > 0) {
        //means the key is found, meaning a duplicate file
        return DUPLICATE_FILE_ERR;
    }
    if(abFiPtr == nullptr) {
        return NULL_PTR_ERROR;
    }
    files.insert(make_pair(filename, abFiPtr));
    return SUCCESS;
}

AbstractFile* SimpleFileSystem::openFile(string filename){
    if(files.count(filename) > 0) {
        AbstractFile* file = files[filename];
        if(openFiles.count(file) == 0) {
            openFiles.insert(file);
            return file;
        }
    }
    return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile *abFiPtr) {
    if(openFiles.count(abFiPtr) > 0) {
        openFiles.erase(abFiPtr);
        return SUCCESS;
    }
    return FILE_NOT_OPEN;
}

int SimpleFileSystem::deleteFile(string filename) {
    auto it = files.find(filename);
    if(it != files.end()){
        AbstractFile *file = files[filename];
        if(openFiles.count(file) == 0) { //but it is not currently open
            files.erase(filename);
            delete file;
            return SUCCESS;
        }
        else{
            return DELETING_OPEN_FILE;
        }
    }
    return FILE_DNE_ERR;
}

set<string> SimpleFileSystem::getFileNames(){

    std::set<std::string> allFileNames;

    // Iterate through the map and add each string to the set
    for (auto pair : files) {
        allFileNames.insert(pair.first);
    }
    return allFileNames;
}