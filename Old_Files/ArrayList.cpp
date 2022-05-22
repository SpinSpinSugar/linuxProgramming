#include "ArrayList.h"
#include <cstring>

ArrayList::ArrayList (int value, size_t size) : _Array(new int[size]), _Size(size), _Capacity(size) {
    //memset(_Array, value, size * sizeof(int)); not working, because memset needs an char (not int)
    for (size_t i = 0; i < _Size; ++i) {
        _Array[i] = value;
    }
}

ArrayList::ArrayList(int value, size_t size, size_t capacity) : _Array(new int[capacity]), _Size(size), _Capacity(capacity) {
    memset(_Array, value, size * sizeof(int));
}

ArrayList::ArrayList(int* array, size_t size, size_t capacity) : _Array(new int[capacity]), _Size(size),
_Capacity(capacity) {
    memcpy(_Array, array, size * sizeof(int));
}

//ArrayList::ArrayList(int* array) : ArrayList(array, array.size) {};

ArrayList::~ArrayList() {
    delete[] _Array;
}

ArrayList::ArrayList(const ArrayList& other) : ArrayList(other._Array, other._Size, other._Capacity) {};

int& ArrayList::operator[](size_t i) {
    return _Array[i];
}

size_t ArrayList::capacity() const {
    return _Capacity;
}

size_t ArrayList::size() const {
    return _Size;
}
void ArrayList::resize(size_t newsize) {
    reserve(newsize);
    for (size_t i = _Size; i < _Capacity; ++i) {
        _Array[i] = 0;
    }
    _Size = newsize;
}

void ArrayList::reserve(size_t newcap) {
    if (_Array == nullptr) return;
    if (newcap <= _Capacity) return;
    int* NewArray = new int[newcap];
    for (size_t i = 0; i < _Size; ++i) {
        NewArray[i] = _Array[i];
    }
    //delete[] _Array;
    _Array = NewArray;
    _Capacity = newcap;
}

void ArrayList::push_back(const int& value) {
    if (_Size == _Capacity) {
        reserve(_Capacity * 2);
    }
    _Array[_Size] = value;
    ++_Size;
}

void ArrayList::pop_back() {
    if (_Size != 0) {
        --_Size;
    }
}

void ArrayList::push_front(const int& value) {
    if (_Size == _Capacity) {
        reserve(_Capacity * 2);
    }
    for (size_t i = _Size - 1; i >= 0; --i) {
        if (i == -1) break;
        _Array[i + 1] = _Array[i];
    }
    _Array[0] = value;
    ++_Size;
}

void ArrayList::pop_front() {
    for (size_t i = 0; i < _Size; ++i) {
        _Array[i] = _Array[i + 1];
    }
    --_Size;
}

void ArrayList::insert(const size_t& position, const int& value) {
    if (position == 0) {
        push_front(value);
        return;
    }

    if (position >= _Size) {
        resize(position);
        _Array[position-1] = value;
        return;
    }
    if (_Size == _Capacity) {
        reserve(_Capacity * 2);
    }
    push_back(_Array[_Size-1]);
    for (size_t i = _Size - 1; i >= position; --i) {
        _Array[i + 1] = _Array[i];
    }
    _Array[position] = value;
}

void ArrayList::erase(const size_t& position) {
    for (size_t i = position; i < _Size; ++i) {
        _Array[i] = _Array[i+1];
    }
    --_Size;
}

void ArrayList::sort() {
    sorter(_Array, 0, _Size - 1);
}

void ArrayList::sorter(int* _Array, size_t left, size_t right) {
    if (right <= left) return;
    size_t j = partition(_Array, left, right);
    sorter(_Array, left, j - 1);
    sorter(_Array, j+1, right);
}

void ArrayList::partition(int* _Array, size_t left, size_t right) {
    size_t i = left;
    size_t j = right;
    while(true) {
        while(_Array[++i] < _Array) {
            if (i == right) break;
        }

        while(_Array[--i] > _Array[left]) {
            if (j == left) break;
        }

        if (i >= j) break;
        swap(_Array[j], _Array[i]);
        return j;
    }
    swap(_Array[left], _Array[j]);
        return j;
}

std::ostream& operator<<(std::ostream& stream, ArrayList& list) {
    if (list.size() == 0) {
        stream << "Empty";
        return stream;
    }
    for (size_t i = 0; i < list.size(); ++i) {
        stream << list[i] << ' ';
    }
    return stream;
}
