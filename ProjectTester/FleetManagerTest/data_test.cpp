//
// Created by lucas on 14/06/2025.
//

#include "DataContainer.h"
#include "gtest/gtest.h"

class DataTest : public testing::Test {
protected:
    void SetUp() override {
        containerVehicle = new VehicleContainer();
        containerVSL = new VSLContainer();
        containerDriver = new DriverContainer();
        containerFinancial = new FinancialContainer();
        containerTrip = new TripContainer();
        containerOrder = new OrderContainer();
        containerData = new DataContainer(
            containerVehicle,
            containerVSL,
            containerDriver,
            containerFinancial,
            containerTrip,
            containerOrder,
            "../dummy-json-data/vehicle.json",
            "../dummy-json-data/vsl.json",
            "../dummy-json-data/driver.json",
            "../dummy-json-data/financial.json",
            "../dummy-json-data/trip.json",
            "../dummy-json-data/order.json");
    }
    void TearDown() override {
        delete containerVehicle;
        delete containerVSL;
        delete containerDriver;
        delete containerFinancial;
        delete containerTrip;
        delete containerOrder;
        delete containerData;
        containerData = nullptr;
    }
    VehicleContainer *containerVehicle;
    VSLContainer *containerVSL;
    DriverContainer *containerDriver;
    FinancialContainer *containerFinancial;
    TripContainer *containerTrip;
    OrderContainer *containerOrder;
    DataContainer *containerData;
};

TEST_F(DataTest, LoadAllData) {
    testing::internal::CaptureStdout();
    containerData->loadOrders();
    string order_output = testing::internal::GetCapturedStdout();
    string order_message = "Loading \"order.json\"...  ✅\n";
    EXPECT_EQ(order_message, order_output);
    testing::internal::CaptureStdout();
    containerData->loadVehicles();
    string vehicle_output = testing::internal::GetCapturedStdout();
    string vehicle_message = "Loading \"vehicle.json\"...  ✅\n";
    EXPECT_EQ(vehicle_message, vehicle_output);
    testing::internal::CaptureStdout();
    containerData->loadVSLs();
    string vsl_output = testing::internal::GetCapturedStdout();
    string vsl_message = "Loading \"vsl.json\"...  ✅\n";
    EXPECT_EQ(vsl_message, vsl_output);
    testing::internal::CaptureStdout();
    containerData->loadDrivers();
    string driver_output = testing::internal::GetCapturedStdout();
    string driver_message = "Loading \"driver.json\"...  ✅\n";
    EXPECT_EQ(driver_message, driver_output);
    testing::internal::CaptureStdout();
    containerData->loadTrips();
    string trip_output = testing::internal::GetCapturedStdout();
    string trip_message = "Loading \"trip.json\"...  ✅\n";
    EXPECT_EQ(trip_message, trip_output);
    testing::internal::CaptureStdout();
    containerData->loadFinancials();
    string financial_output = testing::internal::GetCapturedStdout();
    string financial_message = "Loading \"financial.json\"...  ✅\n";
    EXPECT_EQ(financial_message, financial_output);

    // EXPECT_EQ(containerVehicle->listTrucks().size(), 1);
    // string licensePlateTruck = "AA-AA-AA";
    // EXPECT_NE(containerVehicle->get(licensePlateTruck), nullptr);
    // EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getYear(), 2009);
    // EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getVSL()->getID(), 1);
    // EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getInspection()->getID(), 1);
    // EXPECT_EQ(containerVehicle->get(licensePlateTruck)->getInsurance()->getID(), 1);
    // EXPECT_EQ(containerVehicle->listVans().size(), 1);
    // string licensePlateVan = "BB-BB-BB";
    // EXPECT_NE(containerVehicle->get(licensePlateVan), nullptr);
    // EXPECT_EQ(containerVehicle->get(licensePlateVan)->getYear(), 2025);
    // EXPECT_EQ(containerVehicle->get(licensePlateVan)->getVSL()->getID(), 1);
    // EXPECT_EQ(containerVehicle->get(licensePlateVan)->getInspection()->getID(), 2);
    // EXPECT_EQ(containerVehicle->get(licensePlateVan)->getInsurance()->getID(), 2);
    //
    // EXPECT_EQ(containerVSL->listVSL().size(), 1);
    // EXPECT_NE(containerVSL->get(1), nullptr);
    // EXPECT_EQ(containerVSL->get(1)->getVehicleCount(), 2);
    // EXPECT_EQ(containerVSL->get(1)->getStoredVehicles(1).size(), 2);
    // EXPECT_NE(containerVSL->get(1)->getStoredVehicles(1).front(), nullptr);
    // EXPECT_EQ(containerVSL->get(1)->getStoredVehicles(1).front()->getLicensePlate(), "AA-AA-AA");
    // EXPECT_NE(containerVSL->get(1)->getStoredVehicles(1).back(), nullptr);
    // EXPECT_EQ(containerVSL->get(1)->getStoredVehicles(1).back()->getLicensePlate(), "BB-BB-BB");
    //
    // EXPECT_EQ(containerDriver->listDrivers().size(), 2);
    // EXPECT_NE(containerDriver->get(1), nullptr);
    // EXPECT_EQ(containerDriver->get(1)->getLicense(), 'B');
    // EXPECT_TRUE(containerDriver->get(1)->getVacations().empty());
    // EXPECT_NE(containerDriver->get(2), nullptr);
    // EXPECT_EQ(containerDriver->get(2)->getLicense(), 'C');
    // EXPECT_TRUE(containerDriver->get(2)->getVacations().empty());
    //
    // // Mudar após adicionar dados no original
    // EXPECT_EQ(containerFinancial->listExpense().size(), 0);
    // EXPECT_EQ(containerFinancial->listRevenue().size(), 0);
    //
    // EXPECT_EQ(containerTrip->listTrips().size(), 3);
    // EXPECT_NE(containerTrip->getTrip(1), nullptr);
    // EXPECT_EQ(containerTrip->getTrip(1)->getState(), INCOMING);
    // string licensePlate1 = "AA-AA-AA";
    // EXPECT_EQ(containerTrip->getTrip(1)->getVehicle()->getLicensePlate(), licensePlate1);
    // EXPECT_EQ(containerTrip->getTrip(1)->getOrder()->getOrderID(), 4);
    // EXPECT_EQ(containerTrip->getTrip(1)->getDriver()->getID(), 1);
    // EXPECT_NE(containerTrip->getTrip(2), nullptr);
    // EXPECT_EQ(containerTrip->getTrip(2)->getState(), DELIVERED);
    // EXPECT_EQ(containerTrip->getTrip(2)->getVehicle(), nullptr);
    // EXPECT_EQ(containerTrip->getTrip(2)->getOrder()->getOrderID(), 1);
    // EXPECT_EQ(containerTrip->getTrip(2)->getDriver(), nullptr);
    // EXPECT_NE(containerTrip->getTrip(3), nullptr);
    // EXPECT_EQ(containerTrip->getTrip(3)->getState(), SUPRESSED);
    // EXPECT_EQ(containerTrip->getTrip(3)->getVehicle(), nullptr);
    // EXPECT_EQ(containerTrip->getTrip(3)->getOrder()->getOrderID(), 2);
    // EXPECT_EQ(containerTrip->getTrip(3)->getDriver(), nullptr);
    //
    // EXPECT_EQ(containerOrder->listOrders().size(), 4);
    // EXPECT_NE(containerOrder->get(1), nullptr);
    // EXPECT_EQ(containerOrder->get(1)->getStatus(), IN_PROGRESS);
    // Date date1(6, 12, 2000);
    // EXPECT_EQ(containerOrder->get(1)->getDate(), date1);
    // EXPECT_EQ(containerOrder->get(1)->getClientID(), 3);
    // EXPECT_NE(containerOrder->get(2), nullptr);
    // EXPECT_EQ(containerOrder->get(2)->getStatus(), COMPLETED);
    // Date date2(1, 3, 2005);
    // EXPECT_EQ(containerOrder->get(2)->getDate(), date2);
    // EXPECT_EQ(containerOrder->get(2)->getClientID(), 1);
    // EXPECT_NE(containerOrder->get(3), nullptr);
    // EXPECT_EQ(containerOrder->get(3)->getStatus(), IN_PROGRESS);
    // Date date3(14, 6, 2025);
    // EXPECT_EQ(containerOrder->get(3)->getDate(), date3);
    // EXPECT_EQ(containerOrder->get(3)->getClientID(), 1);
    // EXPECT_NE(containerOrder->get(4), nullptr);
    // EXPECT_EQ(containerOrder->get(4)->getStatus(), IN_PROGRESS);
    // Date date4(22, 1, 2020);
    // EXPECT_EQ(containerOrder->get(4)->getDate(), date4);
    // EXPECT_EQ(containerOrder->get(4)->getClientID(), 2);
}

TEST_F(DataTest, SaveAllData) {
    Date dateOrder(1, 1, 2020);
    Order *order = new Order(999, 999, dateOrder, "ABC", "DEF", 10, 100, 1000, IN_PROGRESS);
    containerOrder->add(*order);
    Truck *truck = new Truck(TRUCK, "CCC", "CCC", 2000, "CC-CC-CC", 120, 98, 120, true);
    containerVehicle->add(truck);
    string vslName = "Nome";
    string vslAddress = "Morada";
    VehicleStorageLocation *vsl = new VehicleStorageLocation(999, vslName, vslAddress, 999, 0);
    containerVSL->add(vsl);
    char driverLicense('C');
    Driver *driver = new Driver(999, driverLicense, 20);
    containerDriver->add(*driver);
    Trip *trip = new Trip(INCOMING, 999, order, 200);
    containerTrip->add(*trip);
    Date dateExpense(1, 1, 2020);
    Expense *expense = new Expense(999, trip, dateExpense, 200, TOLL);
    containerFinancial->addExpense(*expense);
    Date dateRevenue(1, 1, 2020);
    Revenue *revenue = new Revenue(999, order, dateRevenue, 20000);
    containerFinancial->addRevenue(*revenue);

    containerData->saveAllData();

    VehicleContainer *loadedContainerVehicle = new VehicleContainer();
    VSLContainer *loadedContainerVSL = new VSLContainer();
    DriverContainer *loadedContainerDriver = new DriverContainer();
    FinancialContainer *loadedContainerFinancial = new FinancialContainer();
    TripContainer *loadedContainerTrip = new TripContainer();
    OrderContainer *loadedContainerOrder = new OrderContainer();

    DataContainer *loadedContainerData = new DataContainer(
        loadedContainerVehicle,
        loadedContainerVSL,
        loadedContainerDriver,
        loadedContainerFinancial,
        loadedContainerTrip,
        loadedContainerOrder,
        "../dummy-json-data/vehicle.json",
        "../dummy-json-data/vsl.json",
        "../dummy-json-data/driver.json",
        "../dummy-json-data/financial.json",
        "../dummy-json-data/trip.json",
        "../dummy-json-data/order.json");

    loadedContainerData->loadAllData();

    EXPECT_EQ(loadedContainerVehicle->listTrucks().size(), 2);
    string licensePlateTruck = "CC-CC-CC";
    EXPECT_NE(loadedContainerVehicle->get(licensePlateTruck), nullptr);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getYear(), 2000);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getVSL(), nullptr);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getInspection(), nullptr);
    EXPECT_EQ(loadedContainerVehicle->get(licensePlateTruck)->getInsurance(), nullptr);
    EXPECT_EQ(loadedContainerVehicle->listVans().size(), 1);

    EXPECT_EQ(loadedContainerVSL->listVSL().size(), 2);
    EXPECT_NE(loadedContainerVSL->get(999), nullptr);
    EXPECT_EQ(loadedContainerVSL->get(999)->getVehicleCount(), 0);
    EXPECT_EQ(loadedContainerVSL->get(999)->getStoredVehicles(999).size(), 0);

    EXPECT_EQ(loadedContainerDriver->listDrivers().size(), 3);
    EXPECT_NE(loadedContainerDriver->get(999), nullptr);
    EXPECT_EQ(loadedContainerDriver->get(999)->getLicense(), 'C');
    EXPECT_TRUE(loadedContainerDriver->get(999)->getVacations().empty());

    EXPECT_EQ(loadedContainerFinancial->listExpense().size(), 1);
    EXPECT_NE(loadedContainerFinancial->getExpense(999)->getTrip(), nullptr);
    EXPECT_EQ(loadedContainerFinancial->getExpense(999)->getType(), TOLL);
    Date dateExpenseEQ(1, 1, 2020);
    EXPECT_EQ(loadedContainerFinancial->getExpense(999)->getDate(), dateExpenseEQ);
    EXPECT_EQ(loadedContainerFinancial->listRevenue().size(), 1);
    EXPECT_NE(loadedContainerFinancial->getRevenue(999)->getOrder(), nullptr);
    Date dateRevenueEQ(1, 1, 2020);
    EXPECT_EQ(loadedContainerFinancial->getRevenue(999)->getDate(), dateRevenueEQ);

    EXPECT_EQ(containerOrder->listOrders().size(), 5);
    EXPECT_NE(containerOrder->get(999), nullptr);
    EXPECT_EQ(containerOrder->get(999)->getStatus(), IN_PROGRESS);
    Date dateOrderEQ(1, 1, 2020);
    EXPECT_EQ(containerOrder->get(999)->getDate(), dateOrderEQ);
    EXPECT_EQ(containerOrder->get(999)->getClientID(), 999);
}