//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLESTORAGELOCATION_H
#define HEADERS_MODEL_VEHICLESTORAGELOCATION_H
#include <string>
#include <list>
#include <unordered_map>
#include "Vehicle.h"
#include "VehicleContainer.h"

using namespace std;

class VehicleStorageLocation {
  private:
    int id;
    string name;
    string address;
    int capacity;
    int currentVehicleCount;
    unordered_map<int, list<Vehicle *>> vehicles;


  public:
    VehicleStorageLocation();
    VehicleStorageLocation(int id, string name, string address, int capacity,
                           int currentVehicleCount = 0);

    ~VehicleStorageLocation();

    static VehicleStorageLocation addStorageLocation();

    static int removeStorageLocation();

    static void listStorageLocations(list<VehicleStorageLocation> &listVSL);
    void listStoredVehicles() const;
    void addVehicleToStorage(VehicleContainer *container);
    void removeVehicleFromStorage(VehicleContainer *container);
    int getAvailableSpace() const;

    void incrementVehicleCount();

    int getID() const;
    string getName() const;
    string getAddress() const;
    int getCapacity() const;
    int getVehicleCount() const;
    list<Vehicle *> getStoredVehicles() const;

    bool operator== (int id) const;
};

#endif //HEADERS_MODEL_VEHICLESTORAGELOCATION_H
