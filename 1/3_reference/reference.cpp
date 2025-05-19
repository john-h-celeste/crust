#include <iostream>

int main() {
    int count1 = 1;
    int count2 = 1;
    int& r = count1;

    r = count2;

    r++;

    std::cout << "r " << r << std::endl;
    std::cout << "count1 " << count1 << std::endl;
    std::cout << "count2 " << count2 << std::endl;
}