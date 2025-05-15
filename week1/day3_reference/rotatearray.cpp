#include <iostream>

//function prototype
void rotateLeft(const int src[], int dest[], int size, int k);

int main() {
    const int SIZE = 7;
    int list[SIZE] = {1, 2, 3, 4, 5, 6, 7};

    int newList[SIZE];
    rotateLeft(list, newList, SIZE, 8);

    for (int i = 0; i < SIZE; i++) {
        std::cout << newList[i] << ' ';
    }
}

void rotateLeft(const int src[], int dest[], int size, int k) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[(i + k) % size];
    }
}