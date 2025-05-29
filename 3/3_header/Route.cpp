#include <iostream>
#include <cstdlib>

#include "Route.h"

void Route::updateLength() {
    length = rand() % 900 + 75;
}

std::string Route::getSource() const {
    return source;
}

std::string Route::getDestination() const {
    return destination;
}

int Route::getLength() const {
    return length;
}

void Route::setSource(std::string new_source) {
    source = new_source;
    updateLength();
}

void Route::setDestination(std::string new_destination) {
    destination = new_destination;
    updateLength();
}

void printRoute(const Route& route) {
    std::cout << route.getSource() << " -> " << route.getDestination() << ", " << route.getLength() << std::endl;
}
