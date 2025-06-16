#include <iostream>

class A {
public:
    std::string msg1 = "pub :)";

private:
    std::string msg2 = "priv :/";

protected:
    std::string msg3 = "prot >:D";
};

class B : public A {
public:
    void p() {
        std::cout << msg1 << std::endl;
        //std::cout << msg2 << std::endl;
        std::cout << msg3 << std::endl;
    }
};

void p(A a) {
    std::cout << a.msg1 << std::endl;
    //std::cout << a.msg2 << std::endl;
    //std::cout << a.msg3 << std::endl;
}

int main() {
    B b;
    b.p();
    p(b);

    return 0;
}