#ifndef ROUTE_H
#define ROUTE_H

#include <string>

class Route {
    std::string source;
    std::string destination;
    int length;

    void updateLength();

public:
    // why aren't there asymmetric access specifiers?
    std::string getSource() const;
    std::string getDestination() const;
    int getLength() const;
    void setSource(std::string new_source);
    void setDestination(std::string new_destination);
};

void printRoute(const Route& route);

#endif