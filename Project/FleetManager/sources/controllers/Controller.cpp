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
                int category = Utils::getInt("Category (Truck - 1 / Van - 2)");
                if (category == 1) {
                    Truck truck = this->vehicleView.addTruck();
                    VehicleContainer &container = this->model.getVehicleContainer();
                    container.add(truck);
                }
                if (category == 2) {
                    Van van = this->vehicleView.addVan();
                    VehicleContainer &container = this->model.getVehicleContainer();
                    container.add(van);
                }

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
                list<Truck> trucks = container.listTrucks();
                list<Van> vans = container.listVans();
                if (trucks.empty() && vans.empty()) {
                    cout << "THERE ARE NO VEHICLES IN THE RECORDS!\n";
                }
                this->vehicleView.printListTrucks(trucks);
                this->vehicleView.printListVans(vans);
            }
                break;
            case 4: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Truck> trucks = container.listTrucks(true);
                list<Van> vans = container.listVans(true);
                if (trucks.empty() && vans.empty()) {
                    cout << "THERE ARE NO AVAILABLE VEHICLES IN THE RECORDS!\n";
                }
                this->vehicleView.printListTrucks(trucks);
                this->vehicleView.printListVans(vans);
            }
                break;
            case 5: {
                VehicleContainer &container = this->model.getVehicleContainer();
                list<Truck> trucks = container.listTrucks(false);
                list<Van> vans = container.listVans(false);
                if (trucks.empty() && vans.empty()) {
                    cout << "THERE ARE NO UNAVAILABLE VEHICLES IN THE RECORDS!\n";
                }
                this->vehicleView.printListTrucks(trucks);
                this->vehicleView.printListVans(vans);
            }
                break;
            case 6: {
                VehicleContainer &container = this->model.getVehicleContainer();
                Insurance insurance = this->insuranceView.addInsurance(container);
                string licensePlate = insurance.getVehicle().getLicensePlate();
                container.update(licensePlate, insurance);
            }
                break;
            case 7: {
                VehicleContainer &container = this->model.getVehicleContainer();
                Inspection inspection = this->inspectionView.addInspection(container);
                string licensePlate = inspection.getVehicle().getLicensePlate();
                container.update(licensePlate, inspection);
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