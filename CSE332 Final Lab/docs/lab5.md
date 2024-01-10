# Lab 5
Chase Hurwitz, Matteo Dall'Olmo

Custom Macro Command:
We decided to implement the a 'create' Macro Command that allows a user to touch and cat a file all in one. Invoke this command by typing 'cr <new_file_name>'
The command is added to our command prompt in main. If the user types in 'cr' with a valid file name, MacroCommand's execution function is invoked.
It accepts the CreationParsingStrategy and then calls execute on touch and then cat in this order.

TESTS FOR CUSTOM MACRO COMMAND:

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

OUTPUT:

1. Testing a valid use case
Enter a command, 'q' to quit, 'help' for a list of commands, or
help followed by a command name for more information about
that command. Ex: 'help <command_name>'
$  cr a.txt
Enter your input for the file. To save and quit, type ':wq' at the end of your last line, or type ':q' to quit without saving:
testing our touch + cat command
:wq

Enter a command, 'q' to quit, 'help' for a list of commands, or
help followed by a command name for more information about
that command. Ex: 'help <command_name>'
$  ds a.txt
testing our touch + cat command

2. Using it without an extension:
   $  cr hello
   Error executing command

Enter a command, 'q' to quit, 'help' for a list of commands, or
help followed by a command name for more information about
that command. Ex: 'help <command_name>'

3. trying cr with the same name as an existing file:
$  ls
   a.txt
   Enter a command, 'q' to quit, 'help' for a list of commands, or
   help followed by a command name for more information about
   that command. Ex: 'help <command_name>'
   $  cr a.txt
   Error executing command

Enter a command, 'q' to quit, 'help' for a list of commands, or
help followed by a command name for more information about
that command. Ex: 'help <command_name>'

4. Getting metadata of a cr creation:
   $  cr b.txt
   Enter your input for the file. To save and quit, type ':wq' at the end of your last line, or type ':q' to quit without saving:
   HELLLLOOOOOO TESTTINNNGGGG!!!!:wq

Enter a command, 'q' to quit, 'help' for a list of commands, or
help followed by a command name for more information about
that command. Ex: 'help <command_name>'
$  ls -m
a.txt  text  0  
b.txt  text  30

Enter a command, 'q' to quit, 'help' for a list of commands, or
help followed by a command name for more information about
that command. Ex: 'help <command_name>
