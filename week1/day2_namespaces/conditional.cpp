#include <iostream>

int main() {
    float salary;
    std::cout << "What is your salary? ";
    std::cin >> salary;

    float tax = salary > 75000 ? salary - (salary * 0.8) / 1.1 : salary - (salary * 1.7) / 2;

    std::cout << "The tax on a salary of $" << salary << " is $" << tax << std::endl;

    return 0;
}