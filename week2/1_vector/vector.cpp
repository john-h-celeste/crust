#include <iostream>
#include <vector>

void print(std::vector<int> v);

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};

    v.push_back(7);

    std::cout << v.size() << std::endl;

    print(v);

    return 0;
}

void print(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << std::endl;
    }
}