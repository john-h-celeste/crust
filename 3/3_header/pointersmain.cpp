#include <iostream>

#include "Pointers.h"

void testPrintDoubles(int* i, double* d) {
    Pointers p(i, d);

    p.printDoubles();
}

void testPrintDoubles(int i, double* d) {
    testPrintDoubles(&i, d);
}

void testPrintDoubles(int* i, double d) {
    testPrintDoubles(i, &d);
}

void testPrintDoubles(int i, double d) {
    testPrintDoubles(&i, &d);
}

int main() {
    Pointers p;

    int a = 10;
    int* pA = &a;

    p.setPInt(pA);

    std::cout << *p.getPInt() << std::endl;

    int x = 1;
    double y = 3.132;

    Pointers p2(&x, &y);

    std::cout << p2.getPIntValue() << std::endl;
    std::cout << p2.getPDoubleValue() << std::endl;

    Pointers p3(&x, nullptr);

    std::cout << p3.getPIntValue() << std::endl;
    std::cout << p3.getPDoubleValue() << std::endl;

    int i = 8;
    double d = 8.88888;

    Pointers p4(&i, &d);

    p4.printDoubles();

    testPrintDoubles(3, 17);
    testPrintDoubles(5, 0.01);
    testPrintDoubles(0, 4.4);
    testPrintDoubles(nullptr, 17);
    testPrintDoubles(2, nullptr);

    return 0;
}