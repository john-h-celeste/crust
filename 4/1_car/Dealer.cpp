#include "Dealer.h"

#include <iostream>

Dealer::Dealer() {}

Dealer::Dealer(std::string name) : name(name) {}

void Dealer::showInventory() const {
    std::cout << "Cars at " << name << ":" << std::endl;
    for (int i = 0; i < inventory.size(); i++) {
        std::cout << "Car " << i + 1 << std::endl;
        inventory[i].printInfo();
        std::cout << std::endl;
    }
}

void Dealer::addCar(const Car& car) {
    inventory.push_back(car);
}