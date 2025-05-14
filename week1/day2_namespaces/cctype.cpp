#include <iostream>
#include <cctype> // instead of <ctype.h>

int main() {
    for (unsigned char c = 0; c < 128; c++) {
        std::cout << "c: " << c << " ";
        std::cout << "(int)c: " << (int)c << " ";
        std::cout << "isdigit: " << isdigit(c) << " ";
        std::cout << "isalpha: " << isalpha(c) << " ";
        std::cout << "isalnum: " << isalnum(c) << " ";
        std::cout << "toupper: " << toupper(c) << " ";
        std::cout << "tolower: " << tolower(c) << std::endl;
    }

    return 0;
}