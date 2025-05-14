#include <iostream>
#include <iomanip>

int main() {
    float n = 4536.1234;
    std::cout << std::setprecision(1) << n << std::endl;
    std::cout << std::setprecision(2) << n << std::endl;
    std::cout << std::setprecision(3) << n << std::endl;
    std::cout << std::setprecision(4) << n << std::endl;
    std::cout << std::setprecision(5) << n << std::endl;
    std::cout << std::setprecision(6) << n << std::endl;
    std::cout << std::fixed << n << std::endl;
    std::cout << std::showpoint << n << std::endl;
    std::cout << std::setw(30) << n << std::endl;
    std::cout << std::left << n << std::endl;
    std::cout << std::right << n << std::endl;

    return 0;
}