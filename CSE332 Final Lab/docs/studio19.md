# Studio 19

1. 
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
    i->write({'X', 'X', 'X', 'X', '2'});
    vector<char> text = t->read();
    vector<char> image = i->read();
    for(char c : text) {
        cout << c;
    }
    cout << endl;
    for(char c : image) {
        cout << c;
    }
    cout << endl;
    t->write({'X', '0', 'X', '0'});
    i->write({'X', ' ', 'X', ' ', '2'});
    text = t->read();
    image = i->read();
    for(char c : text) {
        cout << c;
    }
    cout << endl;
    for(char c : image) {
        cout << c;
    }
}

OUTPUT:
X X
XXXX
X0X0
X X
Process finished with exit code 0

2. 
A file calls accept and passes a visitor. That visitor then calls visit and passes a reference to the file it is visiting.
While visiting the file, it prints out the file's contents according to that file's type.

3. 
The AbstractFile class delegates the job of printing the file's contents to the terminal to the AbstractFileVisitor class.
In the future, any other functionality that we want to add we can add to the AbstractFileVisitor class and keep the 
interface of the AbstractFile class clean and straightforward.

4. 
The visitor pattern is beneficial because in the AbstractFile class we only have 1 method for all types of files 
to accept all types of visitors. The issue is if we keep adding new types of concrete files, we would need to update a
lot of stuff including our SimpleFileFactory class as well as our BasicDisplayVisitor and our MetadataDisplayVisitor classes.
Delegation gives different objects different tasks so that no single object is responsible for too many things. Otherwise,
classes would get cluttered with messy interfaces.

5. If we had many different types of visitors, each concrete visitor class would have to be updated in order to visit
this new type of file. This could be incredibly complex. Thus, we have to keep track of which visitors can visit which
files and make sure visitors have the right methods to do their jobs.
