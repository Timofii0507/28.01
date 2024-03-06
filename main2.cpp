#include <Windows.h>
#include "HTMLValidator.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string path;
    cout << "Enter the file path: ";
    cin >> path;
    unique_ptr<HTMLValidator> file = make_unique<HTMLValidator>(path);
    file->display();
    return 0;
}