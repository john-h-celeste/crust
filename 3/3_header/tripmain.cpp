#include <cstdlib>
#include <ctime>

#include "Route.h"
#include "Trip.h"

int main() {
    srand(time(0));

    Route summer_trip;
    summer_trip.setSource("Here");
    summer_trip.setDestination("There");

    printRoute(summer_trip);

    Trip disney_trip;

    return 0;
}