#include "ArrayList.h"

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
    for (size_t i = _Size; i =< _Capacity; ++i) {
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
	_Array[sz] = value;
    ++_Size;
}

void ArrayList::pop_back() {
	if (_Size != 0) {
		--_Size;
	}
}

void ArrayList::push_front(const int& value) {
    if (_Size == _Capacity) {
        reserve(_Capacity * 2)
    }
    for (size_t i = _Size - 1; i >= 0; --i) {
        _Array[i+1] = _Array[i];
    }
    _Array[0] = value;
    ++_Size;
}

void ArrayList::pop_front() {
    for (size_t i = 0; i < _Size; ++i) {
        _Array[i] = _Array[i+1];
    }
    --_Size;
}
void ArrayList::insert(const size_t& element, const int& value) {
    if (_Size == _Capacity) {
        reserve(_Capacity * 2)
    }
    for (size_t i = _Size - 1; i >= element; --i) {
        _Array[i+1] = _Array[i];
    }
    _Array[element] = value;
}
size_t ArrayList::partition(int* _Array = this->_Array, size_t left = 0, size_t right = _Size - 1) {
    int v = this->_Array[(left + right) / 2];
    int i = 0;
    int j = right - 1;
    while (i <= j) {
        while (a[i] < v) {
            ++i;
        }
        while (a[j] > v) {
            --j;
        }
        if (i >= j) {
            break;
        }
        swap(_Array[i++], _Array[j--]);
    }
    return j;
}
void ArrayList::sort(int* _Array = this->_Array, size_t left = 0; size_t right = _Size - 1) {
    if (left < right) {
        int q = partition(_Array, left, right)
        sort(_Array, left, q);
        sort(_Array, q + 1, right);
    }
}

std::ostream& operator<<(std::ostream& stream, ArrayList& list) {
    if (_Size == 0) {
        stream << "Empty";
        return stream;
    }
    for (size_t i = 0; i < _Size; ++i) {
        stream << _Array[i] << ' ';
    }
    return stream;
}
