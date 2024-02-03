#ifndef DEVICE_H
#define DEVICE_H

class Observer;

#include <string>
#include <mutex>

#include "ThreadSafeLogger.h"


class Device : protected ThreadSafeLogger {
public:
    ~Device();

    Device(std::mutex* streamMutex = nullptr);

    std::string getName();

    /**
     * @param observer is observer to which device is attached to
     * observer gets messages from device
    */
    void attachDevice(Observer *observer);
    void detachDevice();

    /**
     * @param maxRunTime is the maximum time, it would take device
     * to take measurements
    */
    void setMaxRunTime(size_t maxRunTime);
    void start();
    void run();
    void stop();

    /**
     * produces measurements of some imaginary type
     * lets observer know about the update
    */
    int produceMeasurements();

private:
    static size_t deviceCount;

    std::string m_deviceName;
    Observer* m_observer;
    bool m_isRunning;
    size_t m_maxRunTime;
};

#endif //DEVICE_H