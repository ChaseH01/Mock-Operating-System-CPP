#include "mockos/TextFile.h"

using namespace std;

int main(int argc, char * argv[]) {
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
}