# Studio 17

1. Chase Hurwitz, Matteo Dall'Olmo

2. 
studio17.cpp
   vector<char> stuff = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3'};
   ImageFile imgF("Chase");
   imgF.write(stuff);
   imgF.read();
   }
   
   ouput:
   X X
    X
   X X


Process finished with exit code 0

int main(int argc, char * argv[]) {
vector<char> stuff = { 'X', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '3'};
ImageFile imgF("Chase");
imgF.write(stuff);
imgF.read();
}

XXX
XXX
XXX


Process finished with exit code 0

vector<char> stuff = { 'W', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '3'};
ImageFile imgF("Chase");
int writeReturn = imgF.write(stuff);
if(writeReturn != 0)
{
cout << "Error writing to file. Check that size matches amount of characters and that all characters ar 'X or ' '." << endl;
cout << "Error Value: " << writeReturn << endl;
}
imgF.read();
}

Error writing to file. Check that size matches amount of characters and that all characters ar 'X or ' '.
Error Value: 2


Process finished with exit code 0

int main(int argc, char * argv[]) {
vector<char> stuff = { 'X', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '5'};
ImageFile imgF("Chase");
int writeReturn = imgF.write(stuff);
if(writeReturn != 0)
{
cout << "Error writing to file. Check that size matches amount of characters and that all characters ar 'X or ' '." << endl;
cout << "Error Value: " << writeReturn << endl;
}
imgF.read();
}

Error writing to file. Check that size matches amount of characters and that all characters ar 'X or ' '.
Error Value: 1


Process finished with exit code 0

3. Programming to an interface is so useful because it means our client code has no idea how our operations are defined.
Client code just knows what it can use. By making an abstract base class like AbstractFileSystem, we can change the implementation
of our code without having to change how client code interacts with it. This makes flexible and extensible code!

4. We would need to add code in SimpleFileSystem::createFile(string filename) in order to create a MusicFile for example.
The createFile method is not extensible and depends on understanding how to construct objects of each concrete object.

5. [----------] Global test environment tear-down
   [==========] 25 tests from 3 test suites ran. (21 ms total)
   [  PASSED  ] 25 tests.

Process finished with exit code 0

