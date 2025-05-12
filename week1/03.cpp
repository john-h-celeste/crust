#include <iostream>

int main() {
    int count = 5;
    std::cout << "The count in question: " << count << std::endl;

    if (count = 1) {
        std::cout << "Count is 1" << std::endl;
    } else {
        std::cout << "Count is not 1" << std::endl;
    }

    std::cout << "The count in question: " << count << std::endl;

    double x = 1.0 - 0.1 - 0.1 - 0.1 - 0.1 - 0.1;

    if (x == 0.5) {
        std::cout << "x is 0.5" << std::endl;
    } else {
        std::cout << "x is not 0.5" << std::endl;
    }

    std::cout << "The x in question: " << x << std::endl;
    
    return 0;
}