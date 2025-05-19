#include <iostream>

int main() {
    // Welcome message
    std::cout << "Welcome to the Circle Squarer 2000 (TM)" << std::endl;

    // Read radius
    double radius;
    std::cout << "Enter a radius: ";
    std::cin >> radius;

    // Calculate
    double area = radius * radius * 3.1415926;

    std::cout << "The area of the circle is " << area << std::endl;
    
    return 0;
}