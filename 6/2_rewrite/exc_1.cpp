#include <iostream>

int quotient(int n1, int n2);

int main() {
    int n1, n2;
    std::cout << "enter 2 numbers: ";
    std::cin >> n1 >> n2;

    try {
        std::cout << "the result in question: " << quotient(n1, n2) << std::endl;
    } catch (int ex) {
        std::cout << "zero division of " << ex << " :(" << std::endl;
    }

    return 0;
}

int quotient(int n1, int n2) {
    if (n2 == 0) {
        throw n1;
    }
    return n1 / n2;
}