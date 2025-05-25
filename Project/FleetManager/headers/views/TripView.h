//
// Created by Vitor on 25/05/2025.
//

#ifndef HEADERS_VIEW_TRIPVIEW_H
#define HEADERS_VIEW_TRIPVIEW_H
#include <list>
#include "Trip.h"


class TripView {
public:
    static Trip addTrip();
    static Trip removeTrip();
    static Trip startTrip();
    static Trip endTrip();
    static void updateTrip();
    static void listTripsByDriver(Trip *trip);
    static int getId();

}

#endif //HEADERS_VIEW_TRIPVIEW_H
