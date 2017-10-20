#include <iostream>
#include "linear-algebra.h"

int main() {

    Point A{1, 4, 2};

    std::cout << A << std::endl;

    Matrix B{{1, 6, 3},
             {3, 12, 6}};

    std::cout << B << std::endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}