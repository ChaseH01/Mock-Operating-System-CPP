#include "mockos/MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *img) {
    string filename = img->getName();
    int size = img->getSize();
    string type = "image";

    cout << filename << "  ";
    cout << type << "  ";
    cout << size << "  ";
    cout << endl;
}

void MetadataDisplayVisitor::visit_TextFile(TextFile *txt) {
    string filename = txt->getName();
    int size = txt->getSize();
    string type = "text";

    cout << filename << "  ";
    cout << type << "  ";
    cout << size << "  ";
    cout << endl;
}