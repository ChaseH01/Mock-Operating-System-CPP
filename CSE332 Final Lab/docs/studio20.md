# Studio 20

1. Chase Hurwitz, Matteo Dall'Olmo
2. In the SimpleFileFactory class, files are created dynamically. These pointers are then passed to the PasswordProxy class
when a password protected file is created. So when one of these file pointers goes out of scope, the file must also
be deleted.

3.
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
   
OUTPUT:
Please enter the file's password: password
Please enter the file's password: password
Please enter the file's password: password
X
X


Process finished with exit code 0

The tests ran as expected, if password is incorrect it will say so.

