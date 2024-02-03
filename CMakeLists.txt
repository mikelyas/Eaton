cmake_minimum_required(VERSION 3.16)

project(Eaton VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

set(THREAD_SAFE_LIBRARY_NAME ThreadSafeLogger)
set(DEVICE_LIBRARY_NAME Device)
set(OBSERVER_LIBRARY_NAME Observer)
set(EXECUTABLE_NAME Simulation.exe)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v2.13.9
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(Catch2)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)