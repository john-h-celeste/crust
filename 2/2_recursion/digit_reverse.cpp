#include <iostream>

void print_digits_reverse(unsigned n);
void print_digits_unreverse(unsigned n);

int main() {
    print_digits_reverse(1243);
    print_digits_unreverse(1243);
    std::cout << std::endl;
    return 0;
}

void print_digits_reverse(unsigned n) {
    if (n == 0) {
        std::cout << std::endl;
    } else {
        std::cout << n % 10;
        print_digits_reverse(n / 10);
    }
}

void print_digits_unreverse(unsigned n) {
    if (n == 0) {
        return;
    } else {
        print_digits_unreverse(n / 10);
        std::cout << n % 10;
    }
}