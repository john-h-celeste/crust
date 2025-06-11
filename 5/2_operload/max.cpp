#include <iostream>

// ?: . .* :: cannot be overloaded
// overloading cannot change precedence, associativity, or arity

class A {
public:
    void print() const {
        std::cout << "A" << std::endl;
    }

    bool operator>(const A& other) const {
        return true;
    }
};

template<typename T>
T mymax(const T& v1, const T& v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

int main() {
    mymax(A(), A()).print();

    return 0;
}