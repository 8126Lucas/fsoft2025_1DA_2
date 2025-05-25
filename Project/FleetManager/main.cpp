#include <iostream>
#include "Enterprise.h"
#include "Controller.h"

using namespace std;

int main() {
    Enterprise enterprise("fsoft2025_1DA_2");

    Controller controller(enterprise);
    controller.run();

    cout << "Closing FleetManager..." << endl;

    return 0;
}