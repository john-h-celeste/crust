#include <iostream>

class C {
public:
    C() : value(100) {}
    friend class D;

private:
    int value;
};

class D {
public:
    void print() {
        C c;
        std::cout << c.value << std::endl;
    }
};

int main() {
    D d;
    d.print();

    return 0;
}