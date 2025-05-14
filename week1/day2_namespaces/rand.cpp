#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));

    int number1 = rand() % 10;
    int number2 = rand() % 10;

    std::cout << number1 << " " << number2 << std::endl;

    return 0;
}