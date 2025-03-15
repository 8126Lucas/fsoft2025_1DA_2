#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int year = 0;
    string model;
    double price = 0.0;
    double marketValue = 0.0;
public:
    Vehicle(string b, const int y, string m, const double p) {
        brand = std::move(b);
        year = y;
        model = std::move(m);
        price = p;
        marketValue = p;
    }
    Vehicle() = default;

    void displayInfo() const {
        cout << year << " " << brand << " " << model << endl;
        cout << "Preço: " << price << "€" << endl;
        cout << "Preço de Mercado: " << marketValue << "€" << endl;
    }

    void calculateMarketValue(const int currentYear) {
        const int vehicleAge = currentYear - year;
        marketValue = price * (1.0 - (vehicleAge * 0.1));
        if(marketValue < 0) {
            marketValue = 0;
        }
    }
};
class Truck : public Vehicle {
protected:
    double loadCapacity = 0.0;
public:
    Truck(string b, const int y, string m, const double p, const double load) : Vehicle(std::move(b), y, std::move(m) , p) {
        loadCapacity = load;
    }
    Truck() = default;

    void displayInfo() const {
        Vehicle::displayInfo();
        cout << "Capacidade: " << loadCapacity << " toneladas" << endl;
    }
    bool canCarryLoad(const double weight) {
        return weight <= loadCapacity;
    }
};
class Van : public Vehicle {
protected:
    double cargoSpace = 0.0;
public:
    Van(string b, const int y, string m, const double p, const double space) : Vehicle(std::move(b), y, std::move(m) , p) {
        cargoSpace = space;
    }
    Van() = default;

    void displayInfo() const {
        Vehicle::displayInfo();
        cout << "Capacidade: " << cargoSpace << " metros cúbicos" << endl;
    }

    bool hasEnoughSpace(const double neededSpace) {
        return neededSpace <= cargoSpace;
    }
};

int main() {
    // Ambiente main de teste copiado do Claude

    Truck myTruck("Ford", 2020, "F-150", 45000, 2.5);
    Van myVan("Honda", 2019, "Odyssey", 38000, 140.5);

    cout << "==== My Truck Info ====" << endl;
    myTruck.displayInfo();

    cout << "\n==== My Van Info ====" << endl;
    myVan.displayInfo();

    // Use the special methods
    double loadToCarry = 2.0; // tons
    if (myTruck.canCarryLoad(loadToCarry)) {
        cout << "\nThe truck can carry " << loadToCarry << " tons!" << endl;
    } else {
        cout << "\nThe truck cannot carry " << loadToCarry << " tons!" << endl;
    }

    // Calculate depreciation (assuming current year is 2023)
    int currentYear = 2023;
    myTruck.calculateMarketValue(currentYear);
    myVan.calculateMarketValue(currentYear);

    cout << "\n==== After Depreciation ====" << endl;
    cout << "Truck:" << endl;
    myTruck.displayInfo();
    cout << "\nVan:" << endl;
    myVan.displayInfo();

    return 0;
}