#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    Car(std::string make_ = "-", std::string model_ = "-", int year_ = 1900, double mpg_ = 0.0);

    void printInfo() const;

    double getMPG() const;
public:
    std::string make;
    std::string model;
    int year;
    double mpg;
};
#endif