#ifndef POINTERS_H
#define POINTERS_H

class Pointers {
    int* pInt;
    double* pDouble;

public:
    Pointers();
    Pointers(int* pInt_, double* pDouble_);

    int* getPInt() const;
    double* getPDouble() const;

    int getPIntValue() const;
    double getPDoubleValue() const;

    void setPInt(int* pInt_);
    void setPDouble(double* pDouble_);

    void setPIntValue(int pIntValue_);
    void setPDoubleValue(double pDoubleValue_);

    // print pDouble's value *pInt times
    void printDoubles() const;
};

#endif