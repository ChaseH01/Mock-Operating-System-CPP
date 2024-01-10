#include "mockos/SimpleFileFactory.h"

AbstractFile* SimpleFileFactory :: createFile(std::string filename) {
    if(filename.length() < 5) { return nullptr; }
    string extension = filename.substr(filename.size()-4, 4);

    if(extension == ".txt") {
        TextFile * txt = new TextFile(filename);
        return txt;
    }
    else if(extension == ".img") {
        ImageFile * img = new ImageFile(filename);
        return img;
    }
    return nullptr;
}