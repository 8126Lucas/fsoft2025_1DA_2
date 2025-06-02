//
// Created by lucas on 22/05/2025.
//

#ifndef HEADERS_VIEWS_INSPECTIONVIEW_H
#define HEADERS_VIEWS_INSPECTIONVIEW_H
#include "Inspection.h"
#include "VehicleContainer.h"

class InspectionView {
public:
    Inspection *addInspection(VehicleContainer &container);
    string removeInspection();
};


#endif //HEADERS_VIEWS_INSPECTIONVIEW_H
