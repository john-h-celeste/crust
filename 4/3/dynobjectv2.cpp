#include <iostream>
#include <string>

class Hello {
    static int count;
    int num;
    std::string* messages;
    int size;
    Hello* underside;

public:
    static int instances;

    Hello() : messages(nullptr), size(0) {
        num = ++count;
        instances++;
        std::cout << "hi :)" << std::endl;
        underside = nullptr;
    }

    Hello(const Hello& other) : size(other.size), underside(other.underside) {
        num = ++count;
        instances++;
        std::cout << "hihi :)" << std::endl;
        messages = new std::string[size];
        for (int i = 0; i < size; i++) {
            messages[i] = other.messages[i];
        }
    }

    Hello(int n) : size(n) {
        num = ++count;
        instances++;
        for (int i = 0; i < n; i++) {
            std::cout << "hi " << i + 1 << " of " << n << " ;)" << std::endl;
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
        instances--;
        std::cout << "the heavy is DEAD #" << num << std::endl;
        delete underside;
        delete[] messages;
    }
};

int Hello::count = 0;
int Hello::instances = 0;

void test(Hello h) {
    // implicitly calls copy constructor
    // and destructor
}

int main() {
    Hello* h = new Hello;
    (*h).bye();

    test(*h);
    std::cout << Hello::instances << " instances" << std::endl;

    Hello* h2 = new Hello(5);
    h2->greet();
    h2->bye();

    Hello* har = new Hello[4];
    har[0].bye();
    har[1].bye();
    har[2].bye();
    har[3].bye();

    for (int i = 0; i < 4; i++) {
        test(har[i]);
    }

    delete h;
    delete h2;
    delete[] har;
    delete (Hello*)nullptr;
    
    Hello h3;
    Hello h4(h3);
    Hello h5 = h4;
    
    return 0;
}