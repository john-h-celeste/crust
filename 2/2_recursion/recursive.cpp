#include <iostream>

void countDown(int n);

int main() {
    countDown(5);
    return 0;
}

void countDown(int n) {
    if (n < 1) {
        return;
    } else {
        std::cout << n << std::endl;
        countDown(n - 1);
    }
}