#ifndef SMART_POINTERS_H
#define SMART_POINTERS_H

#include <iostream>

template <typename T>
class MyUniquePtr {
private:
    T* ptr;

public:
    MyUniquePtr(T* p = nullptr);
    ~MyUniquePtr();
    MyUniquePtr(const MyUniquePtr& other) = delete;
    MyUniquePtr& operator=(const MyUniquePtr& other) = delete;
    MyUniquePtr(MyUniquePtr&& other);
    MyUniquePtr& operator=(MyUniquePtr&& other);
    T& operator*() const;
    T* operator->() const;
    T* get() const;
    T* release();
    void reset(T* p = nullptr);
};

template <typename T>
class MySharedPtr {
private:
    T* ptr;
    int* count;

public:
    MySharedPtr(T* p = nullptr);
    ~MySharedPtr();
    MySharedPtr(const MySharedPtr& other);
    MySharedPtr& operator=(const MySharedPtr& other);
    T& operator*() const;
    T* operator->() const;
    T* get() const;
    int use_count() const;
};

#endif
