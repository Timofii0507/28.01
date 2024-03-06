#include <iostream>
#include <memory>
#include <cassert>
#include <Windows.h>

using namespace std;

template <typename T>
class MyUniquePtr {
private:
    T* ptr;
public:
    MyUniquePtr(T* p = nullptr) {
        ptr = p;
    }

    ~MyUniquePtr() {
        delete ptr;
    }

    MyUniquePtr(const MyUniquePtr& other) = delete;

    MyUniquePtr& operator=(const MyUniquePtr& other) = delete;

    MyUniquePtr(MyUniquePtr&& other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

template <typename T>
class MySharedPtr {
private:
    T* ptr;
    int* count;
public:
    MySharedPtr(T* p = nullptr) {
        ptr = p;
        if (p) {
            count = new int(1);
        }
        else {
            count = new int(0);
        }
    }

    ~MySharedPtr() {
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }

    MySharedPtr(const MySharedPtr& other) {
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            (*count)--;
            if (*count == 0) {
                delete ptr;
                delete count;
            }
            ptr = other.ptr;
            count = other.count;
            (*count)++;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    int use_count() const {
        return *count;
    }
};

class Test {
private:
    string name;
public:
    Test(string n) {
        name = n;
        cout << "Об'єкт " << name << " створено" << endl;
    }

    ~Test() {
        cout << "Об'єкт " << name << " знищено" << endl;
    }

    void display() {
        cout << "Це об'єкт " << name << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MyUniquePtr<Test> p1, p2;
    MySharedPtr<Test> p3, p4, p5;

    p1 = MyUniquePtr<Test>(new Test("A"));
    p2 = MyUniquePtr<Test>(new Test("B"));
    p3 = MySharedPtr<Test>(new Test("C"));
    p4 = MySharedPtr<Test>(new Test("D"));
    p5 = MySharedPtr<Test>(new Test("E"));

    p1->display();
    p2->display();
    p3->display();
    p4->display();
    p5->display();

    cout << "Кількість посилань на об'єкт C: " << p3.use_count() << endl;
    cout << "Кількість посилань на об'єкт D: " << p4.use_count() << endl;
    cout << "Кількість посилань на об'єкт E: " << p5.use_count() << endl;

    p1 = move(p2);
    p4 = p3;
    p3 = p5;

    p1->display();
    p3->display();
    p4->display();
    p5->display();

    cout << "Кількість посилань на об'єкт C: " << p3.use_count() << endl;
    cout << "Кількість посилань на об'єкт D: " << p4.use_count() << endl;
    cout << "Кількість посилань на об'єкт E: " << p5.use_count() << endl;

    return 0;
}
