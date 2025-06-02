#include "Car.h"

#include <iostream>

Car::Car(std::string make_, std::string model_, int year_, double mpg_) {
    make = make_;
    model = model_;
    year = year_;
    mpg = mpg_;
}

void Car::printInfo() const {
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "MPG: " << mpg << std::endl;
}

double Car::getMPG() const {
    return mpg;
}
