#include <iostream>
#include <vector>

void print(const std::vector<int> v);

int main() {
    // static assertion failed: std::vector must have a non-const, non-volatile value_type
    //std::vector<const int> v{1, 2, 3, 4, 5, 6};
    
    const std::vector<int> v{1, 2, 3, 4, 5, 6};

    // both of these are error
    //v.push_back(7);
    //v[0] = 0;

    std::cout << v.size() << std::endl;

    print(v);

    return 0;
}

void print(const std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << std::endl;
    }
}