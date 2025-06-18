#include <iostream>

class Parent {
public:
    Parent() {
        std::cout << "parent (imagine memory is allocated here)" << std::endl;
    }

    // virtual destructor is called after child destructor
    virtual ~Parent() {
        std::cout << "parent (imagine memory is deallocated here)" << std::endl;
    }
};

class Child : public Parent {
public:
    Child() {
        std::cout << "child (imagine more memory is allocated here)" << std::endl;
    }

    ~Child() {
        std::cout << "child (imagine extra memory is deallocated here)" << std::endl;
    }
};

int main() {
    Parent* p = new Child;

    delete p;

    return 0;
}