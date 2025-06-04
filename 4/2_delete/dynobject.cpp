#include <iostream>
#include <string>

class Hello {
    static int count;
    int num;
    std::string* messages;
    int size;
    Hello* underside;

public:
    Hello() : messages(nullptr), size(0) {
        num = ++count;
        //std::cout << "hi :)" << std::endl;
        underside = nullptr;
    }

    Hello(int n) : size(n) {
        num = ++count;
        for (int i = 0; i < n; i++) {
            //std::cout << "hi " << i + 1 << " of " << n << " ;)" << std::endl;
        }
        messages = new std::string[n];
        for (int i = 0; i < n; i++) {
            switch (i % 3) {
            case 0:
                messages[i] = "HI";
                break;
            case 1:
                messages[i] = "hello";
                break;
            case 2:
                messages[i] = "salutations!!!!!";
                break;
            }
        }
        underside = new Hello;
    }

    void bye() const {
        std::cout << "i am " << num << " of " << count << ",.,.,.,.... bye...." << std::endl;
    }

    void greet() const {
        for (int i = 0; i < size; i++) {
            std::cout << messages[i] << std::endl;
        }
    }

    ~Hello() {
        std::cout << "the heavy is DEAD #" << num << std::endl;
        delete underside;
        delete[] messages;
    }
};

int Hello::count = 0;

int main() {
    Hello* h = new Hello;
    (*h).bye();

    Hello* h2 = new Hello(5);
    h2->greet();
    h2->bye();

    Hello* har = new Hello[4];
    har[0].bye();
    har[1].bye();
    har[2].bye();
    har[3].bye();

    delete h;
    delete h2;
    delete[] har;
    delete (Hello*)nullptr;

    for (int i = 0; i < 10000000; i++) {
        //Hello hello(999999);
    }

    //std::cout << "a" << std::endl;

    for (int i = 0; i < 10000000; i++) {
        //Hello hello(9999999999999999);
    }

    //std::cout << "b" << std::endl;

    for (int i = 0; i < 10000000; i++) {
        //Hello* hello = new Hello(999999);
    }

    return 0;
}