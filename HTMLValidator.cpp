#include "HTMLValidator.h"

HTMLValidator::HTMLValidator(string path) {
    filename = path;
    input = make_unique<ifstream>(path);
    if (!input->is_open()) {
        cout << "Error opening file " << path << endl;
        exit(1);
    }
    content = string((istreambuf_iterator<char>(*input)), istreambuf_iterator<char>());
}

HTMLValidator::~HTMLValidator() {
    input->close();
}

bool HTMLValidator::validate() {
    size_t pos = 0;
    while (pos < content.length()) {
        pos = content.find('<', pos);
        if (pos == string::npos) {
            break;
        }
        else {
            size_t end = content.find('>', pos + 1);
            if (end == string::npos) {
                return false;
            }
            else {
                string tag = content.substr(pos, end - pos + 1);
                if (tag[1] != '/') {
                    tags.push(tag);
                }
                else {
                    if (tags.empty()) {
                        return false;
                    }
                    string open = tags.top().substr(1, tags.top().length() - 2);
                    string close = tag.substr(2, tag.length() - 3);
                    if (open != close) {
                        return false;
                    }
                    tags.pop();
                }
                pos += tag.length();
            }
        }
    }
    if (tags.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void HTMLValidator::display() {
    bool result = validate();
    if (result) {
        cout << "File " << filename << " is a valid HTML file" << endl;
    }
    else {
        cout << "File " << filename << " is not a valid HTML file" << endl;
    }
}
