#include <iostream>
#include <string>

template<typename T>
T mymax(const T& v1, const T& v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

int main() {
    std::cout << mymax(1, 2) << std::endl;
    std::cout << mymax(1.5, 1.1) << std::endl;
    std::cout << mymax(std::string("wee"), std::string("j")) << std::endl;

    return 0;
}