#include "mockos/ImageFile.h"
#include "mockos/AbstractFileVisitor.h"

using namespace std;

ImageFile::ImageFile(string filename) {
    name = filename;
    size = '0';
}

vector<char> ImageFile::read() {
    return contents;
}
int ImageFile::write(vector<char> v) {
    size = v[v.size()-1];
    int numSize = size-'0';
    contents = v;
    contents.pop_back(); //we don't want to include the very last element, so after copying, we pop it off

    if(v.size()-1 != numSize*numSize) {
        contents.clear();
        size = '0';
        return IMG_SIZE_MISMATCH;
    }

    for(int i = 0; i < v.size()-1; ++i) {
        if(v[i] != ' ' && v[i] != 'X'){
            contents.clear();
            size = '0';
            return IMG_PIXEL_ERR;
        }
    }
    return SUCCESS;
}

AbstractFile* ImageFile::clone(std::string filename) {
    AbstractFile* newFile = new ImageFile(filename+".img");
    newFile->write(this->contents);
    return newFile;
}

int ImageFile::append(vector<char> v) {
    return IMG_APPEND_ERR;
}

unsigned int ImageFile::getSize() {
    return contents.size();
}

string ImageFile::getName() {
    return name;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_ImageFile(this);
}