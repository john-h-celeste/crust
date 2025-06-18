#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    int** data;
    int rows, cols;
    std::cout << "enter numbers of rows and columns: ";
    std::cin >> rows >> cols;

    data = new int*[rows];
    for (int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            data[row][col] = 0;
        }
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << std::setw(4) << data[row][col] << " ";
        }
        std::cout << std::endl;
    }

    for (int row = 0; row < rows; row++) {
        delete[] data[row];
    }

    delete[] data;

    char path[1000];
    std::cout << "enter a file path: ";
    std::cin >> path;

    std::ifstream in(path);

    if (in.fail()) {
        std::cout << "file not found" << std::endl;
        return 1;
    }

    in >> rows;
    in >> cols;

    data = new int*[rows];
    for (int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            in >> data[row][col];
            if (in.eof()) {
                if (row < rows - 1 || col < cols - 1) {
                    std::cout << "hey you didn't give me enough data >:(" << std::endl;
                    return 1;
                }
            }
        }
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << std::setw(4) << data[row][col] << " ";
        }
        std::cout << std::endl;
    }

    std::ofstream out("out.txt");

    out << rows << " " << cols << "\n";

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            out << std::setw(4) << data[row][col] << ((col == cols - 1) ? "\n" : " ");
        }
    }

    out.close();

    for (int row = 0; row < rows; row++) {
        delete[] data[row];
    }

    delete[] data;

    return 0;
}