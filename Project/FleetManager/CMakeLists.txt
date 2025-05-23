cmake_minimum_required(VERSION 3.30)
project(FleetManager)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS_DIR
        ${PROJECT_SOURCE_DIR}/headers)
set(PROJECT_SOURCES_DIR
        ${PROJECT_SOURCE_DIR}/sources)

set(PROJECT_HEADERS_CONTROLLERS_DIR
        ${PROJECT_HEADERS_DIR}/controllers)
set(PROJECT_SOURCES_CONTROLLERS_DIR
        ${PROJECT_SOURCES_DIR}/controllers)
include_directories(
        ${PROJECT_HEADERS_CONTROLLERS_DIR}
        ${PROJECT_SOURCES_CONTROLLERS_DIR})
set(CONTROLLERS_SOURCE_FILES
        ${PROJECT_HEADERS_CONTROLLERS_DIR}/Controller.h
        ${PROJECT_SOURCES_CONTROLLERS_DIR}/Controller.cpp)

set(PROJECT_HEADERS_EXCEPTIONS_DIR
        ${PROJECT_HEADERS_DIR}/exceptions)
set(PROJECT_SOURCES_EXCEPTIONS_DIR
        ${PROJECT_SOURCES_DIR}/exceptions)
include_directories(
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}
        ${PROJECT_SOURCES_EXCEPTIONS_DIR})
set(EXCEPTIONS_SOURCE_FILES
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/NonExistingDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/NonExistingDataException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/DuplicatedDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/DuplicatedDataException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/InvalidDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/InvalidDataException.cpp
)

set(PROJECT_HEADERS_MODEL_DIR
        ${PROJECT_HEADERS_DIR}/model)
set(PROJECT_SOURCES_MODEL_DIR
        ${PROJECT_SOURCES_DIR}/model)
include_directories(
        ${PROJECT_HEADERS_MODEL_DIR}
        ${PROJECT_SOURCES_MODEL_DIR})
set(MODEL_SOURCE_FILES
        ${PROJECT_HEADERS_MODEL_DIR}/Date.h
        ${PROJECT_SOURCES_MODEL_DIR}/Date.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Driver.h
        ${PROJECT_SOURCES_MODEL_DIR}/Driver.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/DriverContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/DriverContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Enterprise.h
        ${PROJECT_SOURCES_MODEL_DIR}/Enterprise.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Expense.h
        ${PROJECT_SOURCES_MODEL_DIR}/Expense.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Inspection.h
        ${PROJECT_SOURCES_MODEL_DIR}/Inspection.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Insurance.h
        ${PROJECT_SOURCES_MODEL_DIR}/Insurance.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Order.h
        ${PROJECT_SOURCES_MODEL_DIR}/Order.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/OrderContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/OrderContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Trip.h
        ${PROJECT_SOURCES_MODEL_DIR}/Trip.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/TripContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/TripContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Truck.h
        ${PROJECT_SOURCES_MODEL_DIR}/Truck.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Vacation.h
        # ${PROJECT_SOURCES_MODEL_DIR}/Vacation.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Van.h
        ${PROJECT_SOURCES_MODEL_DIR}/Van.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Vehicle.h
        ${PROJECT_SOURCES_MODEL_DIR}/Vehicle.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/VehicleContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/VehicleContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/VehicleStorageLocation.h
        ${PROJECT_SOURCES_MODEL_DIR}/VehicleStorageLocation.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/VSLContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/VSLContainer.cpp
)


set(PROJECT_HEADERS_VIEWS_DIR
        ${PROJECT_HEADERS_DIR}/views)
set(PROJECT_SOURCES_VIEWS_DIR
        ${PROJECT_SOURCES_DIR}/views)
include_directories(
        ${PROJECT_HEADERS_VIEWS_DIR}
        ${PROJECT_SOURCES_VIEWS_DIR})
set(VIEWS_SOURCE_FILES
        ${PROJECT_HEADERS_VIEWS_DIR}/DriverView.h
        # ${PROJECT_SOURCES_VIEWS_DIR}/DriverView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/FinancialView.h
        # ${PROJECT_SOURCES_VIEWS_DIR}/FinancialView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/InspectionView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/InspectionView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/InsuranceView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/InsuranceView.cpp
        # ${PROJECT_HEADERS_VIEWS_DIR}/OrderView.h
        # ${PROJECT_SOURCES_VIEWS_DIR}/OrderView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/Utils.h
        ${PROJECT_SOURCES_VIEWS_DIR}/Utils.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/VehicleStorageLocationView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/VehicleStorageLocationView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/VehicleView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/VehicleView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/View.h
        ${PROJECT_SOURCES_VIEWS_DIR}/View.cpp)


add_executable(
        FleetManager
        main.cpp
        ${VIEWS_SOURCE_FILES}
        ${MODEL_SOURCE_FILES}
        ${EXCEPTIONS_SOURCE_FILES}
        ${CONTROLLERS_SOURCE_FILES})

