#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

using namespace std;

class Test {
private:
    string name;

public:
    Test(string n);
    ~Test();
    void display();
};

#endif
