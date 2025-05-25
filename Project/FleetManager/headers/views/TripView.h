//
// Created by Vitor on 25/05/2025.
//

#ifndef HEADERS_VIEW_TRIPVIEW_H
#define HEADERS_VIEW_TRIPVIEW_H
#include <list>
#include "Trip.h"


Class TripView {
public:
    static Trip addTrip();
    static Trip removeTrip();
    static Trip startTrip();
    static Trip endTrip();
    static void Trip updateTrip();
    static void listTripsByDriver(Trip *trip);
    static int getId();

}

#endif //HEADERS_VIEW_TRIPVIEW_H
