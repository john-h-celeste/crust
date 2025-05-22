#include <iostream>

void print(int n, int s);

int main() {
    print(3, 2);
    return 0;
}

void print_(char cs[], int n, int i, int s) {
    if (n == 0) {
        std::cout << cs << std::endl;
        return;
    }
    for (char c = 'A'; c < 'A' + s; c++) {
        cs[i] = c;
        print_(cs, n - 1, i + 1, s);
    }
}

void print(int n, int s) {
    char cs[n + 1];
    cs[n] = '\0';
    print_(cs, n, 0, s);
}