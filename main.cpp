#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"

int main(int argc, char* argv[]) {
    ArrayList c(2, 2);
    c.push_back(11);
    c.push_front(11);
    c.insert(2, 5);
    c.insert(0, 5);
    c.resize(10);
    c.insert(50, 50);
    //c.erase(4);
    //c.push_front(5);
    ArrayList d = c;
    //c.erase(2);
    //ArrayList c;
    /*
    c.push_back(515155);
    c.push_back(123);
    c.push_back(234);
    ArrayList d = c;
    c[0] = 222;
    d[0] = 111;
    c.push_front(333);
    c.push_front(444);
    c.pop_front();
    d.pop_back();
    std::cout << c << c.size() << ' ' << c.capacity() << '\n';
    c.insert(2, 5);
    std::cout << c << c.size() << ' ' << c.capacity() << '\n';
    c.insert(0, 999);
    std::cout << c << '\n';
    c.erase(0);
    std::cout << c << c.size() << ' ' << c.capacity() << '\n';
    std::cout << d << d.size() << ' ' << d.capacity() << '\n';
    std::cout << c[0];
    std::cout << c << '\n';
    */
    std::cout << c << '\n';
    c.sort();
    std::cout << c << '\n';
    std::cout << c.size() << ' ' << c.capacity();
    return EXIT_SUCCESS;
}
