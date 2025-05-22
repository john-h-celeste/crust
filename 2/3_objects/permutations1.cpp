#include <iostream>

void print(int n, int s);

int main() {
    print(8, 8);
    return 0;
}

void print_(std::string str, int n, int i, int s) {
    if (n == 0) {
        std::cout << str << std::endl;
        return;
    }
    for (str[i] = 'A'; str[i] < 'A' + s; str[i]++) {
        bool repeat = false;
        for (int j = 0; j < i; j++) {
            if (str[j] == str[i]) {
                repeat = true;
                break;
            }
        }
        if (!repeat) {
            print_(str, n - 1, i + 1, s);
        }
    }
}

void print(int n, int s) {
    std::string str(n, 'A');
    print_(str, n, 0, s);
}