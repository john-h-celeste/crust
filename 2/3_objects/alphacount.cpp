#include <iostream>

void print();

int main() {
    print();
    return 0;
}

void print() {
    for (char c1 = 'A'; c1 <= 'Z'; c1++) {
        for (char c2 = 'A'; c2 <= 'Z'; c2++) {
            std::cout << c1 << c2 << std::endl;
        }
    }
}