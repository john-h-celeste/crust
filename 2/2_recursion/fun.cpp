#include <iostream>

int fun(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fun(n - 1) + fun(n - 1);
    }
}

int main() {
    std::cout << fun(6) << std::endl;

    return 0;
}