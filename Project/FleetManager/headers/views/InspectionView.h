//
// Created by lucas on 22/05/2025.
//

#ifndef HEADERS_VIEWS_INSPECTIONVIEW_H
#define HEADERS_VIEWS_INSPECTIONVIEW_H
#include "Inspection.h"

class InspectionView {
public:
    static Inspection addInspection(VehicleContainer &container);
    static int removeInspection();
};


#endif //HEADERS_VIEWS_INSPECTIONVIEW_H
