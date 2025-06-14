//
// Created by lucas on 17/05/2025.
//

#ifndef HEADERS_MODEL_VEHICLESTORAGELOCATION_H
#define HEADERS_MODEL_VEHICLESTORAGELOCATION_H
#include <string>
#include <list>
#include <unordered_map>


class Vehicle;

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
    VehicleStorageLocation(int id, string &name, string &address, int capacity,
                           int currentVehicleCount = 0);

    ~VehicleStorageLocation();

    int getAvailableSpace() const;

    void incrementVehicleCount();
    void decrementVehicleCount();

    int getID() const;
    string getName() const;
    string getAddress() const;
    int getCapacity() const;
    int getVehicleCount() const;
    const unordered_map<int, list<Vehicle *>> &getVehicles() const;
    unordered_map<int, list<Vehicle *>> &getVehicles();
    const list<Vehicle *> &getStoredVehicles(int id) const;
    list<Vehicle *> &getStoredVehicles(int id);

    void setID(int id);
    void setName(string name);
    void setAddress(string address);
    void setCapacity(int capacity);
    void setCurrentVehicleCount(int currentVehicleCount);

    void addVehicle(Vehicle *vehicle);

    void removeVehicle(Vehicle *vehicle);

    bool operator== (int id) const;
};

#endif //HEADERS_MODEL_VEHICLESTORAGELOCATION_H
