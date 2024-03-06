#include "FileManager.h"

int main() {
    string path;
    cout << "Enter the file path: ";
    cin >> path;
    unique_ptr<FileManager> file = make_unique<FileManager>(path);
    int choice;
    string query, new_str;
    cout << "Choose an option:" << endl;
    cout << "1. Search for a specific string" << endl;
    cout << "2. Replace a string with a new one" << endl;
    cout << "3. Display file content" << endl;
    cout << "4. Reverse file content" << endl;
    cout << "5. Exit the program" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Enter the string to search for: ";
        cin >> query;
        file->search(query);
        break;
    case 2:
        cout << "Enter the string to replace: ";
        cin >> query;
        cout << "Enter the new string: ";
        cin >> new_str;
        file->replace(query, new_str);
        break;
    case 3:
        file->display();
        break;
    case 4:
        file->reverse();
        break;
    case 5:
        cout << "Thank you for using the program. Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
    return 0;
}
