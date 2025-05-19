#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a string with spaces: ";
    std::getline(std::cin, s);

    std::cout << "Your string was: " << s << std::endl;

    return 0;
}