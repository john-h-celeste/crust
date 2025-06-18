#include <iostream>
#include <string>

class MyException : public std::logic_error {
    int exception_code;

public:
    MyException(const char* msg, int code): std::logic_error(msg), exception_code(code) {}

    void print() const {
        std::cout << "My Exception: code " << exception_code << ", message " << what() << std::endl;
    }
};

class Fraction {
    int num, den;

public:
    Fraction(int num = 0, int den = 1) : num(num), den(den) {}

    // return the integer part of this fraction
    int quotient() const {
        if (den == 0) {
            throw num;
        }
        if ((num < 0) ^ (den < 0)) {
            // fraction is negative
            throw std::string("negative fraction");
        }
        if (num > 100) {
            throw std::logic_error("wee zer budd chummy paller");
        }
        if (num > 80) {
            throw MyException("me myne", 15);
        }
        if (num == 21) {
            throw "i dont like 21";
        }

        return num / den;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    return out << "Fraction(" << f.num << " / " << f.den << ")";
}

void testfrac(const Fraction& f) {
    try {
        std::cout << f << " = " << f.quotient() << std::endl;
    } catch (int ex) {
        std::cout << "division by 0" << std::endl;
    } catch (std::string& msg) {
        // const char* isn't autocasted
        std::cout << msg << std::endl;
    } catch (MyException& exc) {
        // has to go before catching std::logic_error
        // or MyException will always be caught as an std::logic_error
        exc.print();
    } catch (std::logic_error& exc) {
        std::cout << exc.what() << std::endl;
    } catch (...) {
        std::cout << "some other exception idk" << std::endl;
        throw; // rethrow :)
    }
}

int main() {
    Fraction f1(1, 3);
    Fraction f2(12, 3);
    Fraction f3(10, 3);
    Fraction f4(10, 0);
    Fraction f5(-10, 5);
    Fraction f6(-10, -5);
    Fraction f7(10, -5);
    Fraction f8(1023, 10);
    Fraction f9(-1023, -10);
    Fraction f10(90, 10);
    Fraction f11(21, 10);

    testfrac(f1);
    testfrac(f2);
    testfrac(f3);
    testfrac(f4);
    testfrac(f5);
    testfrac(f6);
    testfrac(f7);
    testfrac(f8);
    testfrac(f9);
    testfrac(f10);
    try {
        testfrac(f11);
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    std::cout << "bye" << std::endl;

    return 0;
}