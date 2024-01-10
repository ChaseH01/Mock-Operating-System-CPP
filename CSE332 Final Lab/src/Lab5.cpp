#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/CreationParsingStrategy.h"

using namespace std;

int main(int argc, char * argv[]) {

    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    AbstractCommand* touch = new TouchCommand(fs, ff);
    AbstractCommand* ls = new LSCommand(fs);
    AbstractCommand* rm = new RemoveCommand(fs);
    AbstractCommand* cat = new CatCommand(fs);
    AbstractCommand* ds = new DisplayCommand(fs);
    AbstractCommand* copy = new CopyCommand(fs);

    auto* p = new RenameParsingStrategy();
    auto* rn = new MacroCommand(fs);
    rn->setParseStrategy(p);
    rn->addCommand(copy);
    rn->addCommand(rm);

    auto* s = new CreationParsingStrategy();
    auto* create = new MacroCommand(fs);
    create->setParseStrategy(s);
    create->addCommand(touch);
    create->addCommand(cat);

    CommandPrompt cp = CommandPrompt();
    cp.setFileSystem(fs);
    cp.setFileFactory(ff);
    cp.addCommand("touch", touch);
    cp.addCommand("ls", ls);
    cp.addCommand("rm", rm);
    cp.addCommand("cat", cat);
    cp.addCommand("ds", ds);
    cp.addCommand("cp", copy);
    cp.addCommand("rn", rn);
    cp.addCommand("cr", create);

    int CP_retrunVal = cp.run();
    return CP_retrunVal;
}