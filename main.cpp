#include <iostream>
#include "LinkedList.h"

int main(int argc, char* argv[]) {
	LinkedList a;
	a.push_front(7);
	a.push_front(6);
	a.push_front(5);
	a.push_front(4);
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);
	a.push_front(0);
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.insert(10, 777);
	std::cout << a << '\n';
	a.swap(2, 5);
	a.swap(2, 13); //do nothing
	a.insert(12, 50); //do nothing
	a.erase(12); //do nothing
	std::cout << a << '\n' << a.front() << '\n' << a.back() << '\n';
	return EXIT_SUCCESS;
}