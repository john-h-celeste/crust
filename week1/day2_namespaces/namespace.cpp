#include <iostream>

namespace first {
    void hello() {
        std::cout << "hI" << std::endl;
    }
}

namespace second {
    void hello() {
        std::cout << "hi again!!!!" << std::endl;
    }
}

int main() {
    first::hello();
    second::hello();

    return 0;
}