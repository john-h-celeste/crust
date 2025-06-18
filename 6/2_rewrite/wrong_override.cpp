#include <iostream>

class Parent {
public:
    virtual void p(int a) const {
        std::cout << "parent " << a << std::endl;
    }
};

class Child : Parent {
public:
    int p(uint a) const {
        std::cout << "child " << a << std::endl;
        return a + 1;
    }
};

int main() {
    Parent p;
    Child c;

    p.p(15);
    std::cout << c.p(16) << std::endl;
    std::cout << c.p(-16) << std::endl;

    return 0;
}