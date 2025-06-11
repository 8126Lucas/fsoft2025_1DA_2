
cmake_minimum_required(VERSION 3.21)
project(FleetManagerTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googleTestLib/googletest-main)

set(PROJECT_HEADERS_DIR "../../Project/FleetManager/headers")
set(PROJECT_SOURCES_DIR "../../Project/FleetManager/sources")

set(APP_SOURCES
        ${PROJECT_SOURCES_DIR}/controllers/Controller.cpp
        ${PROJECT_SOURCES_DIR}/exceptions/NonExistingDataException.cpp
        ${PROJECT_SOURCES_DIR}/exceptions/DuplicatedDataException.cpp
        ${PROJECT_SOURCES_DIR}/exceptions/InvalidDataException.cpp
        ${PROJECT_SOURCES_DIR}/model/Vehicle.cpp
        ${PROJECT_SOURCES_DIR}/model/Date.cpp
        ${PROJECT_SOURCES_DIR}/model/Driver.cpp
        ${PROJECT_SOURCES_DIR}/model/DriverContainer.cpp
        ${PROJECT_SOURCES_DIR}/model/Enterprise.cpp
        ${PROJECT_SOURCES_DIR}/model/Expense.cpp
        ${PROJECT_SOURCES_DIR}/model/FinancialContainer.cpp
        ${PROJECT_SOURCES_DIR}/model/Inspection.cpp
        ${PROJECT_SOURCES_DIR}/model/Insurance.cpp
        ${PROJECT_SOURCES_DIR}/model/Order.cpp
        ${PROJECT_SOURCES_DIR}/model/OrderContainer.cpp
        ${PROJECT_SOURCES_DIR}/model/Revenue.cpp
        ${PROJECT_SOURCES_DIR}/model/Trip.cpp
        ${PROJECT_SOURCES_DIR}/model/TripContainer.cpp
        ${PROJECT_SOURCES_DIR}/model/Truck.cpp
        ${PROJECT_SOURCES_DIR}/model/Vacation.cpp
        ${PROJECT_SOURCES_DIR}/model/Van.cpp
        ${PROJECT_SOURCES_DIR}/model/VehicleContainer.cpp
        ${PROJECT_SOURCES_DIR}/model/VehicleStorageLocation.cpp
        ${PROJECT_SOURCES_DIR}/model/VSLContainer.cpp
        ${PROJECT_SOURCES_DIR}/views/DriverView.cpp
        ${PROJECT_SOURCES_DIR}/views/FinancialView.cpp
        ${PROJECT_SOURCES_DIR}/views/InspectionView.cpp
        ${PROJECT_SOURCES_DIR}/views/InsuranceView.cpp
        ${PROJECT_SOURCES_DIR}/views/OrderView.cpp
        ${PROJECT_SOURCES_DIR}/views/TripView.cpp
        ${PROJECT_SOURCES_DIR}/views/Utils.cpp
        ${PROJECT_SOURCES_DIR}/views/VacationView.cpp
        ${PROJECT_SOURCES_DIR}/views/VehicleStorageLocationView.cpp
        ${PROJECT_SOURCES_DIR}/views/VehicleView.cpp
        ${PROJECT_SOURCES_DIR}/views/View.cpp
        ${PROJECT_SOURCES_DIR}/serial/DriverSerialization.cpp
        ${PROJECT_SOURCES_DIR}/serial/FinancialSerialization.cpp
        ${PROJECT_SOURCES_DIR}/serial/OrderSerialization.cpp
        ${PROJECT_SOURCES_DIR}/serial/TripSerialization.cpp
        ${PROJECT_SOURCES_DIR}/serial/VehicleSerialization.cpp
        ${PROJECT_SOURCES_DIR}/serial/VehicleStorageLocationSerialization.cpp
        ${PROJECT_SOURCES_DIR}/serial/DataContainer.cpp
)



enable_testing()


add_executable(runTests
        order_test.cpp
        date_test.cpp
        trip_test.cpp
        driver_test.cpp
        financial_test.cpp
        ${APP_SOURCES}
)


target_include_directories(runTests PRIVATE
        # Headers do Google Test
        ${CMAKE_CURRENT_SOURCE_DIR}/googleTestLib/googletest-main/googletest/include
        # Headers da sua aplicação
        ${PROJECT_HEADERS_DIR}/controllers
        ${PROJECT_HEADERS_DIR}/exceptions
        ${PROJECT_HEADERS_DIR}/model
        ${PROJECT_HEADERS_DIR}/views
        ${PROJECT_HEADERS_DIR}/serial
)


target_link_libraries(runTests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)