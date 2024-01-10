#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"

using namespace std;

TextFile::TextFile(string filename) {
    name = filename;
}

vector<char> TextFile::read() {
    return contents;
}
int TextFile::write(vector<char> v) {
    contents = v;
    return 0;
}
int TextFile::append(vector<char> v) {
    for(char c : v) {
        contents.push_back(c);
    }
    return 0;
}

AbstractFile* TextFile::clone(std::string filename) {
    AbstractFile* newFile = new TextFile(filename+".txt");
    newFile->write(this->contents);
    return newFile;
}

unsigned int TextFile::getSize() {
    return contents.size();
}
string TextFile::getName() {
    return name;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_TextFile(this);
}