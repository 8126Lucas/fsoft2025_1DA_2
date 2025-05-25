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

void Controller::runVehicle() {
    int op = -1;
    do {
        op = this->view.menuVehicle();
        switch (op) {
            case 0:
                run();
                break;
            case 1: {
                Vehicle vehicle = this->vehicleView.addVehicle();
                VehicleContainer &container = this->model.getVehicleContainer();
                container.add(vehicle);
            }
                break;
            case 2: {
                string licensePlate = this->vehicleView.removeVehicle();
                VehicleContainer &container = this->model.getVehicleContainer();
                container.remove(licensePlate);
            }
                break;
            case 3: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Vehicle> vehicles = container.list();
                if (!vehicles.empty()) {
                    this->vehicleView.printListVehicles(vehicles);
                }
                else {
                    cout << "THERE ARE NO VEHICLES IN THE RECORDS!\n";
                }
                break;
            }
            case 4: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Vehicle> vehicles = container.list(true);
                if (!vehicles.empty()) {
                    this->vehicleView.printListVehicles(vehicles);
                }
                else {
                    cout << "THERE ARE NO AVAILABLE VEHICLES!\n";
                }
                break;
            }
            case 5: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Vehicle> vehicles = container.list(false);
                if (!vehicles.empty()) {
                    this->vehicleView.printListVehicles(vehicles);
                }
                else {
                    cout << "THERE ARE NO UNAVAILABLE VEHICLES!\n";
                }
                break;
            }
            case 6: {
                Insurance insurance = this->insuranceView.addInsurance();
                string licensePlate = insurance.getVehicle().getLicensePlate();
                VehicleContainer &container = this->model.getVehicleContainer();
                container.update(licensePlate, insurance);
                // ver para update VSLContainer
            }
                break;
            case 7: {
                Inspection inspection = this->inspectionView.addInspection();
                string licensePlate = inspection.getVehicle().getLicensePlate();
                VehicleContainer &container = this->model.getVehicleContainer();
                container.update(licensePlate, inspection);
                // ver para update VSLContainer
            }
                break;
            case 8: {
                VehicleStorageLocation vsl = this->vslView.addVSL();
                VSLContainer &container = this->model.getVSLContainer();
                container.add(vsl);
            }
                break;
            case 9: {
                int id = this->vslView.removeVSL();
                VSLContainer &container = this->model.getVSLContainer();
                container.remove(id);
            }
                break;
            case 10: {
                VSLContainer &container = this->model.getVSLContainer();
                list<VehicleStorageLocation> locations = container.list();
                if (!locations.empty()) {
                    this->vslView.printListVSL(locations);
                }
                else {
                    cout << "THERE ARE NO STORAGE LOCATIONS RECORDED!";
                }
            }
                break;
            case 11: {
                VSLContainer &container = this->model.getVSLContainer();
                int vslID = Utils::getInt("VSL ID");
                VehicleStorageLocation *vsl = container.get(vslID);
                this->vslView.printListStoredVehicles(*vsl);
                // MUDAR PARA TER UMA LISTA ANTES DE DAR PRINT
            }
                break;
            case 12: {
                VSLContainer &containerVSL = this->model.getVSLContainer();
                VehicleContainer &containerVehicle = this->model.getVehicleContainer();
                this->vslView.addVehicleToStorage(&containerVSL, &containerVehicle);

            }
                break;
            case 13: {
                VSLContainer &containerVSL = this->model.getVSLContainer();
                VehicleContainer &containerVehicle = this->model.getVehicleContainer();
                this->vslView.removeVehicleFromStorage(&containerVSL, &containerVehicle);
            }
                break;
            default: break;
        }
    } while (op != 0);
}