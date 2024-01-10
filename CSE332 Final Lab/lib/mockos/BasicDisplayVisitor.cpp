#include "mockos/BasicDisplayVisitor.h"
#include <cmath>

void BasicDisplayVisitor::visit_TextFile(TextFile *txt) {
    for(char c : txt->read()) {
        cout << c;
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile *img) {
    int numSize = sqrt(img->getSize());
    vector<char> contents = img->read();

    //print horizontal ascending and vertical descending
    for(int Y=numSize-1; Y>=0; --Y){
        for(int X=0; X<=numSize-1; ++X){
            int idx = numSize * Y + X;
            cout << contents[idx];
        }
        cout<<endl;
    }
    cout << endl;
}