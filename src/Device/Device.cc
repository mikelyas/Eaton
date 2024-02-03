#include "Device.h"
#include "Observer.h"

#include <cstdlib>
#include <iostream>
#include <thread>


size_t Device::deviceCount = 0;

Device::Device(std::mutex *streamMutex)
    : ThreadSafeLogger(streamMutex), m_maxRunTime(10), m_isRunning(false), m_observer(nullptr)
{
    m_deviceName = "Device" + std::to_string(++deviceCount);
}

Device::~Device() 
{
    stop();
    detachDevice();
}

std::string Device::getName()
{
    return m_deviceName;
}

void Device::setMaxRunTime(size_t maxRunTime) 
{
    m_maxRunTime = maxRunTime;
}

void Device::attachDevice(Observer *observer)
{
    if (m_observer) {
        printMessage(getName() + ": Device is already attached.");
        return;
    }
    m_observer = observer;
    printMessage(getName() + ": Device attached successfully.");
}

void Device::detachDevice()
{
    m_observer = nullptr;
}

void Device::start() {
    printMessage(getName() + ": Starting...");
}

void Device::run()
{
    m_isRunning = true;
    // Start the working simulation
    while (m_isRunning) {
        srand(time(0));
        unsigned int runTime = rand() % m_maxRunTime + 1;

        // Sleep for some time (simulating work)
        std::this_thread::sleep_for(std::chrono::seconds(runTime));

        // Produce measurement
        produceMeasurements();
        printMessage(getName() + ": Measurement took " + std::to_string(runTime) + " seconds.");
    }
    // device got stop signal and left the loop
    printMessage(getName() + ": Stopping.");
}

int Device::produceMeasurements()
{
    srand(time(0));
    int randomMeasurement = rand();

    std::string msg = m_deviceName + " measured " + std::to_string(randomMeasurement) + " rph.";
    if (m_observer) {
        m_observer->update(msg);
    }
    return randomMeasurement;
}

void Device::stop() 
{
    if (m_isRunning) {
        printMessage(getName() + ": Sending signal to stop!");
        // Set the flag to stop the loop in the run method
        m_isRunning = false;
    }
}