# Studio 18

1. Chase Hurwitz, Matteo Dall'Olmo

2. 
   The method within SimpleFileSystem, createFile, needs to know exactly what types of files it can create beforehand.
   If we want to extend this functionality we would need to go into the file system class and change the createFile
   method. If those created a new file type we would need to define that type and then edit the createFile method
   in each of our file system implementations.

3.
   The abstract factory pattern is advantageous because different implementations of a file system can use the same
   factory pattern to create files. If new concrete file types are added all that needs to be changed is the file
   factory and all the different file systems will be functional.

4.
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
   i->write({'X', ' ', 'X', ' ', '2'});
   t->read();
   i->read();
   }
   
Output:
X X
X
X 

5.
   SimpleFileSystem doesn't depend on any concrete file types. It is only concerned with the AbstractFile type and
   can be easily extended to support more concrete file types.