#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include <string>

#include "Car.h"

class Dealer {
public:
    std::string name;
    std::vector<Car> inventory;

    Dealer();
    Dealer(std::string name);
    
    void showInventory() const;
    void addCar(const Car& car);
};
#endif