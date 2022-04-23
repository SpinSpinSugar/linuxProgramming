#include "ArrayList.h"

ArrayList::ArrayList(size_t size, int value) : _Array(new int[size]), _Size(size), _Capacity(size) {
    memset(_Array, value, sizeof(_Array));
}

ArrayList::~ArrayList() {
    delete[] _Array;
}

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
    for (size_t i = _Size; i <= _Capacity; ++i) {
        _Array[i] = 0;
    }
    _Size = newsize;
}
void ArrayList::reserve(size_t newcap) {
    if (newcap <= _Capacity) return;
    int* NewArray = new int[newcap];
    for (size_t i = 0; i < _Size; ++i) {
        NewArray[i] = _Array[i];
    }
    delete[] _Array;
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
    for (size_t i = _Size; i > 0; --i) {
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
    if (_Size == _Capacity) {
        reserve(_Capacity * 2);
    }
    for (size_t i = _Size - 1; i >= position; --i) {
        _Array[i + 1] = _Array[i];
    }
    _Array[position] = value;
}

void ArrayList::erase(const size_t& position) {

}

/*size_t ArrayList::partition(size_t left = 0, size_t right = 0) {
    int v = this->_Array[(left + right) / 2];
    int i = 0;
    int j = right - 1;
    while (i <= j) {
        while (this->_Array[i] < v) {
            ++i;
        }
        while (this->_Array[j] > v) {
            --j;
        }
        if (i >= j) {
            break;
        }
        std::swap(this->_Array[i++], this->_Array[j--]);
    }
    return j;
}
void ArrayList::sort(size_t left = 0, size_t right = 0) {
    if (left < right) {
        int q = partition(left, right);
        sort(left, q);
        sort(q + 1, right);
    }
}
*/
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