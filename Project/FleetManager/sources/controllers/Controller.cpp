//
// Created by lucas on 15/05/2025.
//

#include "Controller.h"
#include <iostream>
#include "Utils.h"

using namespace std;

Controller::Controller(Enterprise &enterprise) {
    this->model = enterprise;
}

void Controller::run() {
    int op = -1;
    do {
        op = this->view.menuEnterprise();
        switch (op) {
            case 1:
                runVehicle();
                break;
            case 2:
                runDriver();
                break;
            case 3:
                runTrip();
                break;
            case 4:
                runFinancial();
                break;
            case 5:
                runOrder();
                break;
            default:
                break;
        }
    } while (op != 0);
}
