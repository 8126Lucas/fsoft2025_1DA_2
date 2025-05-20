//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLESTORAGELOCATION_H
#define HEADERS_MODEL_VEHICLESTORAGELOCATION_H
#include <string>

using namespace std;

class VehicleStorageLocation {
  private:
    int id;
    string name;
    string address;
    int capacity;
    int currentVehicleCount;

  public:
    VehicleStorageLocation();
    VehicleStorageLocation(int id, string name, string address, int capacity,
                           int currentVehicleCount = 0);

    ~VehicleStorageLocation();

    VehicleStorageLocation addStorageLocation();
    void removeStorageLocation();
    void listStorageLocations();
    void listStoredVehicles();
    void addVehicleToStorage();
    void removeVehicleFromStorage();
    int getAvailableSpace();

    void incrementVehicleCount();

    int getID() const;

    bool operator== (int id) const;
};

#endif //HEADERS_MODEL_VEHICLESTORAGELOCATION_H
