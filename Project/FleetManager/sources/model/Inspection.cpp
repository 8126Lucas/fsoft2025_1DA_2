//
// Created by lucas on 17/05/2025.
//

#include "Inspection.h"


int Inspection::getID() const {
    return id;
}

bool Inspection::isDued() {
    this->updateToday();
    if (this->date < this->today) {return true;}
    if (this->date == this->today) {return true;}
    return false;
}

int Inspection::getRemainingDays() const {
    return this->date - this->today;
}

void Inspection::updateToday() {
    this->today = Date::getToday();
}
