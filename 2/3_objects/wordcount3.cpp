#include <iostream>

void print(int n, int s);

int main() {
    print(3, 2);
    return 0;
}

void print_(std::string str, int n, int i, int s) {
    if (n == 0) {
        std::cout << str << std::endl;
        return;
    }
    for (str[i] = 'A'; str[i] < 'A' + s; str[i]++) {
        print_(str, n - 1, i + 1, s);
    }
}

void print(int n, int s) {
    std::string str('A', n);
    print_(str, n, 0, s);
}