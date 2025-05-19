#include <vector>
#include <iostream>

void rotateLeft(std::vector<char>& v, int n);
void rotateRight(std::vector<char>& v, int n);

int main(void) {
    std::vector<char> attendance;

    attendance.push_back('Z');
    attendance.push_back('Q');
    attendance.push_back('T');
    rotateLeft(attendance, 2);

    attendance.push_back('Q');
    rotateRight(attendance, 1);

    attendance.push_back('V');
    rotateLeft(attendance, 4);

    std::cout << attendance[0] << attendance[1] << attendance[2] << attendance[3] << attendance[4] << std::endl;

    return 0;
}

void rotateLeft(std::vector<char>& v, int n) {
    for (int _ = 0; _ < n; _++) {
        v.push_back(v.front());
        v.erase(v.begin());
    }
}

void rotateRight(std::vector<char>& v, int n) {
    rotateLeft(v, v.size() - n);
}