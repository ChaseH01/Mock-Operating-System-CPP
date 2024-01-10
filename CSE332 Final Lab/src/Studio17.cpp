#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"


using namespace std;

int main(int argc, char * argv[]) {

    string filename = "filename.img";
    unsigned int fileSize = 0;
    ImageFile T(filename);
    vector<char> stuff = { 'Y', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '3'};
    cout << "WRITE VALUE: " << T.write(stuff) << endl;
    cout << (fileSize) << endl;
    cout << T.getSize() << endl;


//    vector<char> stuff = { 'X', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '3'};
//    SimpleFileSystem sfs;
//    ImageFile * imgPtr = new ImageFile("filename.img");
//    return sfs.deleteFile(imgPtr->getName());

//
//    SimpleFileSystem simpFileSys = SimpleFileSystem();
//    ImageFile img1 = ImageFile("bob");
//    TextFile txt1  = TextFile("Nancy");
//
//
//    simpFileSys.addFile("bob", &img1);
//    simpFileSys.addFile("NANCY", &txt1);
//
//    txt1.write(stuff);
//    txt1.read();
//
//    img1.write(stuff);
//    img1.read();
//
//    simpFileSys.openFile("bob");
//
//    simpFileSys.createFile("YUHU.img");
//    auto ptr = simpFileSys.openFile("YUHU.img");
//    cout <<ptr<<endl;
//    cout << simpFileSys.deleteFile("YUHU.img") <<endl;
//    cout<< simpFileSys.closeFile(ptr) <<endl;
//    cout << simpFileSys.deleteFile("YUHU.img")<<endl;

//    vector<char> stuff = { 'X', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '5'};
//    ImageFile imgF("Chase");
//    int writeReturn = imgF.write(stuff);
//    if(writeReturn != 0)
//    {
//        cout << "Error writing to file. Check that size matches amount of characters and that all characters ar 'X or ' '." << endl;
//        cout << "Error Value: " << writeReturn << endl;
//    }
//    imgF.read();
}