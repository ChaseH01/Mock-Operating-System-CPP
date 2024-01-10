#pragma once

#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
public:
    PasswordProxy(AbstractFile* file, string password);
    ~PasswordProxy();
    vector<char> read() override;
    int write(vector<char> v) override;
    int append(vector<char> v) override;
    unsigned int getSize() override;
    string getName() override;
    void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* clone(string filename) override;
private:
    AbstractFile* file;
    string password;
protected:
    string passwordPrompt();
};