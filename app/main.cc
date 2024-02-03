#include <iostream>
#include <thread>
#include <vector>

#include "Device.h"
#include "Observer.h"


int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <numDevices>" << std::endl;
        return 1;
    }

    const size_t numDevices = std::stoi(argv[1]);
    if (numDevices <= 0) {
        std::cerr << "Number of devices must be a positive integer." << std::endl;
        return 1;
    }

    // mutex for visualizing purposes only
    std::mutex streamMutex;

    Observer observer(&streamMutex);

    std::vector<std::shared_ptr<Device>> devices;
    for (size_t i = 0; i < numDevices; i++) {
        devices.push_back(std::make_shared<Device>(&streamMutex));
    }
    std::vector<std::thread> threads;

    for (std::shared_ptr<Device> dev : devices) {
        dev->setMaxRunTime(5);
        dev->attachDevice(&observer);

        dev->start();
        std::thread thr(&Device::run, dev);
        threads.push_back(std::move(thr));
    }

    // Wait to simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(10));

    for (size_t i = 0; i < numDevices; ++i) {
        devices[i]->stop();
        threads[i].join();
    }

    std::cout << "Observer received " << observer.getMessageCount() << " messages." << std::endl;

    return 0;
}
