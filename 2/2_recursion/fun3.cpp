#include <iostream>

void fun3(int n) {
    if (n <= 0) return;
    if (n > 1000) return;

    std::cout << n << " ";
    
    fun3(2 * n);

    std::cout << n << " ";
}

int main() {
    fun3(10);
    std::cout << std::endl;

    return 0;
}