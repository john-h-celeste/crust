#include "Matrix.h"

#include <iostream>
#include <iomanip>
#include <fstream>

Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}

Matrix::Matrix(const char* path) {
    std::ifstream in(path);

    if (in.fail()) {
        throw std::logic_error("file not found");
    }

    in >> rows;
    in >> cols;

    if (rows <= 0 || cols <= 0) {
        throw std::logic_error("matrix must have positive numbers of rows and columns");
    }

    data = new int*[rows];
    for (int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            in >> data[row][col];
            if (in.eof()) {
                if (row < rows - 1 || col < cols - 1) {
                    throw std::logic_error("hey you didn't give me enough data >:(");
                }
            }
        }
    }
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
    data = new int*[rows];
    for (int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            data[row][col] = other.data[row][col];
        }
    }
}

const Matrix &Matrix::operator=(const Matrix &other) {
    for (int row = 0; row < rows; row++) {
        delete[] data[row];
    }

    delete[] data;

    rows = other.rows;
    cols = other.cols;

    data = new int*[rows];
    for (int row = 0; row < rows; row++) {
        data[row] = new int[cols];
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            data[row][col] = other.data[row][col];
        }
    }

    return *this;
}

Matrix::~Matrix() {
    for (int row = 0; row < rows; row++) {
        delete[] data[row];
    }

    delete[] data;
}

void Matrix::print() const {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << std::setw(4) << data[row][col] << " ";
        }
        std::cout << std::endl;
    }
}