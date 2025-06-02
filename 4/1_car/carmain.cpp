#include <iostream>

#include "Car.h"
#include "Dealer.h"

bool isEfficient(const Car& car);

int countEfficientCars(const Dealer& dealer);

int main() {
    Dealer dealer("Crusty Ahh Cars TM LLC");

    Car defaultcar;
    defaultcar.printInfo();
    dealer.addCar(defaultcar);

    Car car1("Honda", "Civic");
    car1.printInfo();
    dealer.addCar(car1);

    Car car2("Ford", "Car", 2000, 1000.0);
    car2.printInfo();
    dealer.addCar(car2);

    Car car3("Chev", "Submarine", 1984, 10.0);
    car3.printInfo();
    dealer.addCar(car3);

    std::cout << std::endl;

    dealer.showInventory();

    std::cout << "The dealer's third car is " << (isEfficient(dealer.inventory[2]) ? "efficient" : "not efficient") << "." << std::endl;
    std::cout << "The dealer's fourth car is " << (isEfficient(dealer.inventory[3]) ? "efficient" : "not efficient") << "." << std::endl;

    return 0;
}

bool isEfficient(const Car& car) {
    return car.getMPG() > 20.0 ? true : false;
}

int countEfficientCars(const Dealer &dealer) {
    int count = 0;
    for (Car c : dealer.inventory) {
        if (isEfficient(c)) {
            count++;
        }
    }
    return count;
}
