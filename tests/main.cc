#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "Observer.h"
#include "Device.h"


TEST_CASE("Observed messages count")
{
    Observer observer;
    
    Device device1;
    device1.attachDevice(&observer);
    size_t measurementsCount1 = 3;
    for (size_t i = 0; i < measurementsCount1; ++i) {
        device1.produceMeasurements();
    }
    device1.detachDevice();

    Device device2;
    device2.attachDevice(&observer);
    size_t measurementsCount2 = 2;
    for (size_t i = 0; i < measurementsCount2; i++) {
        device2.produceMeasurements();
    }
    device2.detachDevice();

    REQUIRE(observer.getMessageCount() == measurementsCount1 + measurementsCount2);
}

TEST_CASE("Observed messages count after detachment")
{
    Observer observer;

    Device device;
    device.attachDevice(&observer);
    size_t measurementsCountAttached = 3;
    for (size_t i = 0; i < measurementsCountAttached; ++i) {
        device.produceMeasurements();
    }
    device.detachDevice();

    size_t measurementsCountDetached = 2;
    for (size_t i = 0; i < measurementsCountAttached; ++i) {
        device.produceMeasurements();
    }

    REQUIRE(observer.getMessageCount() == measurementsCountAttached);
}