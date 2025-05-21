#include <iostream>

int powerRecursive(int base, int exp);
int powerRecursive2(int base, int exp);

int main() {
    std::cout << powerRecursive(7, 7) << std::endl;
    std::cout << powerRecursive2(7, 7) << std::endl;

    return 0;
}

int powerRecursive(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else {
        return base * powerRecursive(base, exp - 1);
    }
}

int powerRecursive2_(int base, int exp, int accumulator) {
    if (exp == 0) {
        return accumulator;
    } else {
        return powerRecursive2_(base, exp - 1, accumulator * base);
    }
}

int powerRecursive2(int base, int exp) {
    return powerRecursive2_(base, exp, 1);
}