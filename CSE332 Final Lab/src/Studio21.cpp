#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"

using namespace std;

int main(int argc, char * argv[]) {

    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    AbstractCommand* touch = new TouchCommand(fs, ff);
   // AbstractCommand* ls = new LSCommand()
    CommandPrompt cp = CommandPrompt();
    cp.setFileSystem(fs);
    cp.setFileFactory(ff);
    cp.addCommand("touch", touch);

    cp.run();

    cout << fs->openFile("a.txt")->getName();
}