#include <iostream>

// Double the elements of `arr` in place
void doubleElements(int* arr, int size);

// Print the elements of `arr`
void printArray(const int* arr, int size);

// Double the elements of `arr` and return a new array
int* doubleElementsNew(const int* arr, int size);

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int* arr2 = doubleElementsNew(arr, 5);

    printArray(arr, 5);
    printArray(arr2, 5);

    return 0;
}

void doubleElements(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int *doubleElementsNew(const int *arr, int size) {
    int* new_arr = new int[size];
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i] * 2;
    }
    return new_arr;
}
