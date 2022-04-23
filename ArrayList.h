#pragma once
#include <iostream>

class ArrayList {
private:
    int* _Array;
    size_t _Size;
    size_t _Capacity;
public:
    ArrayList(size_t n, const int& value = 0);
    int& operator[](size_t i);
    size_t capacity() const;
    size_t size() const;
    void resize(size_t newsize);
    void reserve(size_t newcap);
    void push_back(const int& value);
    void pop_back();
    void push_front(const int& value);
    void pop_front();
    void insert(const int& element, const int& position);
    void remove(const int& position);
    void sort();
    friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);
private:
    void partition(size_t left, size_t right); //method for sort()
}; 
