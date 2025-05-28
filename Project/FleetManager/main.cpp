#include <iostream>
#include "Enterprise.h"
#include "Controller.h"
#include "InvalidDataException.h"

using namespace std;

int main() {
    try {
        Enterprise enterprise("fsoft2025_1DA_2");

        Controller controller(enterprise);
        controller.run();

        cout << "Closing FleetManager..." << endl;

        return 0;
    } catch (InvalidDataException &e) {
        cout << "Problema: " << e.what() << endl;
    } catch (const exception &error) {
        cout << "Erro: " << error.what() << endl;
        return 1;
    }
}