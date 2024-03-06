#include "FileManager.h"

using namespace std;

FileManager::FileManager(string path) {
    filename = path;
    input = make_unique<ifstream>(path);
    if (!input->is_open()) {
        cout << "Error opening file " << path << endl;
        exit(1);
    }
    output = make_unique<ofstream>(path, ios::app);
    if (!output->is_open()) {
        cout << "Error opening file " << path << endl;
        exit(1);
    }
    content = string((istreambuf_iterator<char>(*input)), istreambuf_iterator<char>());
}

FileManager::~FileManager() {
    input->close();
    output->close();
}

void FileManager::search(string query) {
    int count = 0;
    size_t pos = 0;
    while (pos < content.length()) {
        pos = content.find(query, pos);
        if (pos == string::npos) {
            break;
        }
        else {
            count++;
            pos += query.length();
        }
    }
    cout << "Found " << count << " occurrences of \"" << query << "\" in file " << filename << endl;
}

void FileManager::replace(string old_str, string new_str) {
    int count = 0;
    size_t pos = 0;
    while (pos < content.length()) {
        pos = content.find(old_str, pos);
        if (pos == string::npos) {
            break;
        }
        else {
            content.replace(pos, old_str.length(), new_str);
            count++;
            pos += new_str.length();
        }
    }
    cout << "Replaced " << count << " occurrences of \"" << old_str << "\" with \"" << new_str << "\" in file " << filename << endl;
    output->seekp(0);
    *output << content;
}

void FileManager::display() {
    cout << content << endl;
}

void FileManager::reverse() {
    std::reverse(content.begin(), content.end());
    cout << "Content of file " << filename << " reversed" << endl;
    output->seekp(0);
    *output << content;
}
