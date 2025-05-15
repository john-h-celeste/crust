#include <iostream>

// global variable
// has file scope
// not a good idea
// unless const
const int x = 10;

void foo();
void bar(int n);

int main() {
    std::cout << x << std::endl;

    // local variable
    // block scope
    int x = 100;

    std::cout << x << std::endl;

    for (int x = 0; x < 10; x++) {
        std::cout << x << std::endl;
    }

    foo();

    bar(17);
    bar(3);

    return 0;
}

void foo() {
    // will access the global x
    std::cout << x << std::endl;
}

void bar(int n) {
    static int x = 0;

    x += n;

    std::cout << x << std::endl;
}