#include <iostream>
#include "ArrayList.h"

int main(int argc, char* argv[]) {
    ArrayList c(1, 1);
    c[0] = 5;
    c[1] = 13;
    std::cout << c[0] << ' ' << c[1];
    return EXIT_SUCCESS;
}