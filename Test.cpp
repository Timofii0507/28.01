#include "Test.h"

Test::Test(string n) : name(n) {
    cout << "��'��� " << name << " ��������" << endl;
}

Test::~Test() {
    cout << "��'��� " << name << " �������" << endl;
}

void Test::display() {
    cout << "�� ��'��� " << name << endl;
}
