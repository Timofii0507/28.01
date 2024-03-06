#ifndef HTMLVALIDATOR_H
#define HTMLVALIDATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <memory>

using namespace std;

class HTMLValidator {
private:
    unique_ptr<ifstream> input;
    string content;
    string filename;
    stack<string> tags;

public:
    HTMLValidator(string path);
    ~HTMLValidator();
    bool validate();
    void display();
};

#endif 
