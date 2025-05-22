#include <iostream>

void print(int n, int s);

int main() {
    print(3, 2);
    return 0;
}

struct link {
    link* last;
    char c;
};

void print__(link* l) {
    if (l == nullptr) {
        return;
    } else {
        print__(l->last);
        std::cout << l->c;
    }
}

void print_(link* l, int n, int s) {
    if (n == 0) {
        print__(l);
        std::cout << std::endl;
        return;
    }
    for (char c = 'A'; c < 'A' + s; c++) {
        link next{l, c};
        print_(&next, n - 1, s);
    }
}

void print(int n, int s) {
    print_(nullptr, n, s);
}