#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Route {
    std::string source;
    std::string destination;
    int length;

    void updateLength() {
        length = rand() % 900 + 75;
    }

public:
    // why aren't there asymmetric access specifiers?
    std::string getSource() {
        return source;
    }

    std::string getDestination() {
        return destination;
    }

    int getLength() {
        return length;
    }

    void setSource(std::string new_source) {
        source = new_source;
        updateLength();
    }

    void setDestination(std::string new_destination) {
        destination = new_destination;
        updateLength();
    }
};

void printRoute(Route& route) {
    std::cout << route.getSource() << " -> " << route.getDestination() << ", " << route.getLength() << std::endl;
}

int main() {
    srand(time(0));

    Route summer_trip;
    summer_trip.setSource("Here");
    summer_trip.setDestination("There");

    printRoute(summer_trip);

    return 0;
}