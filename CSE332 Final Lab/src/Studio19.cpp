#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"


using namespace std;

int main(int argc, char * argv[]) {

    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    AbstractFile* t = ff->createFile("text.txt");
    AbstractFile* i = ff->createFile("image.img");
    fs->addFile("text.txt", t);
    fs->addFile("image.img", i);
    fs->openFile(t->getName());
    fs->openFile(i->getName());
    t->write({'X', ' ', 'X', ' '});
    i->write({'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X', ' ', '3'});

    AbstractFileVisitor* bdv = new BasicDisplayVisitor();
    t->accept(bdv);
    i->accept(bdv);
}