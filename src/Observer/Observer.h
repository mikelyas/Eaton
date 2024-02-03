#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <cstdint>
#include <mutex>

#include "ThreadSafeLogger.h"


/**
 * Observer class, which looks after devices and 
 * receives messages from them
*/
class Observer : protected ThreadSafeLogger {
public:

    Observer(std::mutex *streamMutex = nullptr);

    /**
     * @param msg is a received message from device
    */
    void update(const std::string &msg);

    size_t getMessageCount() const;

private:
    size_t m_msgCount;
};

#endif //OBSERVER_H