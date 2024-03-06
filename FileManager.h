#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class FileManager {
private:
    unique_ptr<ifstream> input;
    unique_ptr<ofstream> output;
    string content;
    string filename;

public:
    FileManager(string path);
    ~FileManager();
    void search(string query);
    void replace(string old_str, string new_str);
    void display();
    void reverse();
};

#endif 