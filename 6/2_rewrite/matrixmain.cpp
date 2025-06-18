#include <iostream>
#include <iomanip>

#include "Matrix.h"

int main() {
    char path[1000];
    std::cout << "enter a file path: ";
    std::cin >> path;

    Matrix m(path);

    m.print();

    return 0;
}