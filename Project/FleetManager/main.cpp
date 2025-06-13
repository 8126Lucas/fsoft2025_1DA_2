#include <iostream>
#include "Enterprise.h"
#include "Controller.h"
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "NonExistingDataException.h"

using namespace std;

int main() {
    try {
        Enterprise enterprise("fsoft2025_1DA_2");

        Controller controller(enterprise);
        controller.run();

        cout << "\nClosing FleetManager..." << endl;

        return 0;
    }
    catch (const DuplicatedDataException &error) {
        cout << error.what() << endl;
        return 1;
    }
    catch (const NonExistingDataException &error) {
        cout << error.what() << endl;
        return 2;
    }
    catch (const InvalidDataException &error) {
        cout << error.what() << endl;
        return 3;
    }
}