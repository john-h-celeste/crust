#include <iostream>
#include <string>
#include <cmath>

void rotate_left(std::string& src, int nRotations);

int main(void) {
    std::string long_string("1u34g6rjyjddfhsdf5adh6jsdfj1sldj4kao9sjdf");
    int n_rotations = pow((100 * 2 - 75 / 3 + 20 % 7 + 20 + 12 / 4), 3);

    rotate_left(long_string, n_rotations);

    std::string attend(long_string, 5, 5);
    std::cout << attend << std::endl;

    return 0;
}

// void rotate_left(std::string& src, int nRotations) {
//     for (int _ = 0; _ < nRotations; _++) {
//         src.insert(src.begin(), src.back());
//         src.pop_back();
//     }
// }

void rotate_left(std::string& src, int nRotations) {
    nRotations %= src.length();
    src = src.substr(src.length() - nRotations, src.length()) + src.substr(0, src.length() - nRotations);
}