# Studio 16

1. Chase Hurwitz, Matteo Dall'Olmo
2. Create an abstract base class with all of its member functions as pure virtual. Have each derived class define these
functions in their own specific implementations. Client code should define a pointer to the base class, and 
then we can dynamically set that pointer to refer to specific derived classes and use that pointer as needed.

Client code:
AbstractFile *f;
f= &TextFile;
f->read(); //this is going to call TextFile's specific read function, using the base class

3. This is an example of Interface inheritance. The member variables of the TextFile class will be private in order to 
hide the implementation details from the outside world.
4. I created a vector with 3 chars in it and wrote those to the TextFile, and the program successfully added
those values and printed them out. I then made another vector of chars and used the append function. The
program successfully printed those out too along with the correct size. I also tested the getSize and getName functions.
   
   TextFile f = TextFile("File Name");
   vector<char> v = {'0', '1', '2'};
   f.write(v);
   f.read();
   vector<char> v2 = {'a', 'b', 'c'};
   cout << "after append" << endl;
   f.append(v2);
   f.read();
   cout << "size: " << f.getSize() << endl;
   cout << "name: " << f.getName() << endl;

Output:
012
after append
012abc
size: 6
name: File Name

5.   
   We used an alias to the abstract class as the static type and pointed our pointer to the TextFile as its dynamic type.   

   AbstractFile *f;
   TextFile t = TextFile("File Name");
   f = &t;
   vector<char> v = {'0', '1', '2'};
   f->write(v);
   f->read();
   vector<char> v2 = {'a', 'b', 'c'};
   cout << "after append" << endl;
   f->append(v2);
   f->read();
   cout << "size: " << f->getSize() << endl;
   cout << "name: " << f->getName() << endl;

6. 
[==========] Running 5 tests from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 5 tests from textfile
   [ RUN      ] textfile.constructor
   [       OK ] textfile.constructor (0 ms)
   [ RUN      ] textfile.write
   [       OK ] textfile.write (0 ms)
   [ RUN      ] textfile.append
   [       OK ] textfile.append (0 ms)
   [ RUN      ] textfile.read
   [       OK ] textfile.read (0 ms)
   [ RUN      ] textfile.readWithAppend
   [       OK ] textfile.readWithAppend (0 ms)
   [----------] 5 tests from textfile (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 5 tests.