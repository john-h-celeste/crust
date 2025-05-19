#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello!";

    std::cout << s1 << std::endl;

    std::string s2(s1);

    std::cout << s2 << std::endl;

    std::string s3(100, '#');

    std::cout << s3 << std::endl;

    s1 += s2;

    std::cout << s1 << std::endl;

    std::string s4(s1, 4, 5); // from 4 for 5

    std::cout << s4 << std::endl;

    std::string s5(s1, 4, 50); // from 4 for 50

    std::cout << s5 << std::endl;

    std::string s6;

    std::cout << s6.length() << std::endl;

    std::cout << (char)(8 + '0') << std::endl;

    return 0;
}