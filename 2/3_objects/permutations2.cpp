#include <iostream>

void print(int n, int s);

int main() {
    print(8, 8);
    return 0;
}

void print_(std::string str, bool used[], int n, int i, int s) {
    if (n == 0) {
        std::cout << str << std::endl;
        return;
    }
    for (str[i] = 'A'; str[i] < 'A' + s; str[i]++) {
        if (!used[str[i] - 'A']) {
            used[str[i] - 'A'] = true;
            print_(str, used, n - 1, i + 1, s);
            used[str[i] - 'A'] = false;
        }
    }
}

void print(int n, int s) {
    std::string str(n, 'A');
    bool used[n];
    print_(str, used, n, 0, s);
}