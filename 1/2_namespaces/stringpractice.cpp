#include <iostream>
#include <string>

int main() {
    std::string s1;
    s1 += (s1.length() + 8) + '0';
    s1 += 'R';
    std::string s2 = "D";
    s1 += (s1 < s2) ? s2 : s1;
    s1 += "SU";
    std::cout << s1 << std::endl;

    return 0;
}