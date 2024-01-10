#include "mockos/PasswordProxy.h"

PasswordProxy::PasswordProxy(AbstractFile *FILE, std::string PASSWORD) : file(FILE), password(PASSWORD) {}

PasswordProxy::~PasswordProxy() {
    delete file;
}

string PasswordProxy::passwordPrompt() {
    string passwordAttempt;
    cout << "Please enter the password for: " << this->getName() << endl;
    cin >> passwordAttempt;
    return passwordAttempt;
}

vector<char> PasswordProxy::read() {
    vector<char> emptyVect;
    if(passwordPrompt() != password) {
        cout << "Incorrect password" << endl << "Read failed" << endl;
        return emptyVect;
    }
    return file->read();
}

int PasswordProxy::write(vector<char> v) {
    if(passwordPrompt() != password) {
        cout << "Incorrect password" << endl << "Write failed" << endl;
        return INCORRECT_FILE_PASS;
    }
    return file->write(v);
}

int PasswordProxy::append(vector<char> v) {
    if(passwordPrompt() != password) {
        cout << "Incorrect password" << endl << "Append failed" << endl;
        return INCORRECT_FILE_PASS;
    }
    return file->append(v);
}

unsigned int PasswordProxy::getSize() {
    return file->getSize();
}

string PasswordProxy::getName() {
    return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *visitor) {
    if(passwordPrompt() != password) {
        cout << "Incorrect password" << endl << "Accept failed" << endl;
        return;
    }
    file->accept(visitor);
}

AbstractFile* PasswordProxy::clone(std::string filename) {
    AbstractFile* newFile = this->file->clone(filename);
    newFile->write(this->file->read());
    AbstractFile* newPassProx = new PasswordProxy(newFile, password);
    return newPassProx;
}