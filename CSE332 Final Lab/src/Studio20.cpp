#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

using namespace std;

int main(int argc, char * argv[]) {

    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    AbstractFile* i = ff->createFile("image.img");
    PasswordProxy pp = PasswordProxy(i, "password");
    AbstractFileVisitor* visitor = new BasicDisplayVisitor();

    pp.write({'X', ' ', ' ', 'X', '2'});
    vector<char> contents = pp.read();
    pp.accept(visitor);
}