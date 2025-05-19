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
        headers/model/Enterprise.h
        headers/model/VehicleStorageLocation.h
        headers/views/VehicleStorageLocationView.h)

set(PROJECT_HEADERS_MODEL_DIR
        ${PROJECT_HEADERS_DIR}/model)
set(PROJECT_SOURCES_MODEL_DIR
        ${PROJECT_SOURCES_DIR}/model)
include_directories(
        ${PROJECT_HEADERS_MODEL_DIR}
        ${PROJECT_SOURCES_MODEL_DIR})


set(PROJECT_HEADERS_VIEWS_DIR
        ${PROJECT_HEADERS_DIR}/views)
set(PROJECT_SOURCES_VIEWS_DIR
        ${PROJECT_SOURCES_DIR}/views)
include_directories(
        ${PROJECT_HEADERS_VIEWS_DIR}
        ${PROJECT_SOURCES_VIEWS_DIR})


add_executable(
        FleetManager
        main.cpp
        ${VIEWS_SOURCE_FILES}
        ${MODEL_SOURCE_FILES}
        ${EXCEPTIONS_SOURCE_FILES}
        ${CONTROLLERS_SOURCE_FILES})

