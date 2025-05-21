//
// Created by lucas on 17/05/2025.
//

#include "Insurance.h"

int Insurance::getID() const {
    return id;
}

bool Insurance::isExpired() {
    this->updateToday();
    if (this->endDate < this->today) {return true;}
    if (this->endDate == this->today) {return true;}
    return false;
}

int Insurance::getRemainingDays() const {
    return this->endDate - this->today;
}

void Insurance::updateToday() {
    this->today = Date::getToday();
}
