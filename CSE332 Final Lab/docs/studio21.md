# Studio 21

1. 
It is important to declare a virtual destructor in the base class to properly destruct subclass objects. This way, all 
objects get properly cleaned up and avoid memory leaks. After the subclass destructor gets called, it invokes the 
base class destructor.

2. 
The dependencies of the object are created externally rather than within CommandPrompt. This means that if the project
requires multiple or different file systems, files, or factories, the command prompt can be easily configured to support them.

3. 
int main(int argc, char * argv[]) {

   AbstractFileSystem* fs = new SimpleFileSystem();
   AbstractFileFactory* ff = new SimpleFileFactory();
   AbstractCommand* touch = new TouchCommand(fs, ff);
   CommandPrompt cp = CommandPrompt();
   cp.setFileSystem(fs);
   cp.setFileFactory(ff);
   cp.addCommand("touch", touch);

   cp.run();

   cout << fs->openFile("a.txt")->getName(); 
   }
   
OUTPUT:
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command. Ex: help <command_name>
$  touch a.txt

Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command. Ex: help <command_name>
$  q
a.txt