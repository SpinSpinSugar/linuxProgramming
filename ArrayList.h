#pragma once
#include <iostream>

class ArrayList {
private:
    int* _Array = nullptr;
    size_t _Size = 0;
    size_t _Capacity = 1;
public:
    ArrayList() {};
    ArrayList(size_t size, int value);
    ~ArrayList();
    int& operator[](size_t i);
    size_t capacity() const;
    size_t size() const;
    void resize(size_t newsize);
    void reserve(size_t newcap);
    void push_back(const int& value);
    void pop_back();
    void push_front(const int& value);
    void pop_front();
    void insert(const size_t& position, const int& value);
    void erase(const size_t& position);
    //void sort(size_t left = 0, size_t right = 0);
    friend std::ostream& operator<<(std::ostream& stream, ArrayList& list);
private:
    //size_t partition(size_t left = 0, size_t right = 0); //method for sort()
};