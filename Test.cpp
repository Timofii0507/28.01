#include "Test.h"

Test::Test(string n) : name(n) {
    cout << "ќб'Їкт " << name << " створено" << endl;
}

Test::~Test() {
    cout << "ќб'Їкт " << name << " знищено" << endl;
}

void Test::display() {
    cout << "÷е об'Їкт " << name << endl;
}
