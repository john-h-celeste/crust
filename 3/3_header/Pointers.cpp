#include <iostream>

#include "Pointers.h"

Pointers::Pointers() : pInt(nullptr), pDouble(nullptr)  {}

Pointers::Pointers(int* pInt_, double* pDouble_) : pInt(pInt_), pDouble(pDouble_)  {}

int* Pointers::getPInt() const {
    return pInt;
}

double* Pointers::getPDouble() const {
    return pDouble;
}

int Pointers::getPIntValue() const {
    if (pInt != nullptr) {
        return *pInt;
    }
    return 0;
}

double Pointers::getPDoubleValue() const {
    if (pDouble != nullptr) {
        return *pDouble;
    }
    return 0;
}

void Pointers::setPInt(int* pInt_) {
    pInt = pInt_;
}

void Pointers::setPDouble(double* pDouble_) {
    pDouble = pDouble_;
}

void Pointers::setPIntValue(int pIntValue_) {
    if (pInt != nullptr) {
        *pInt = pIntValue_;
    }
}

void Pointers::setPDoubleValue(double pDoubleValue_) {
    if (pDouble != nullptr) {
        *pDouble = pDoubleValue_;
    }
}

void Pointers::printDoubles() const {
    int count = getPIntValue();
    int val = getPDoubleValue();
    for (int i = 0; i < count; i++) {
        std::cout << val << std::endl;
    }
}
