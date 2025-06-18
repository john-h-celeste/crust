#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    int** data;
    int rows, cols;

public:
    Matrix();
    Matrix(const char* path);
    Matrix(const Matrix& other);
    const Matrix& operator=(const Matrix& other);
    ~Matrix();

    void print() const;
};

#endif