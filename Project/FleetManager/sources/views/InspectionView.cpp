//
// Created by lucas on 22/05/2025.
//

#include "InspectionView.h"
#include "Utils.h"

Inspection InspectionView::addInspection() {
    Inspection inspection = Utils::setInspection();
    return inspection;
}

int InspectionView::removeInspection() {
    const int id = Utils::getInt("Inspection ID");
    return id;
}