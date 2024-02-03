#ifndef THREADSAFELOGGER_H
#define THREADSAFELOGGER_H

#include <mutex>
#include <iostream>


/**
 * ThreadSafeLogger is created for visual purposes only.
 * It lets classes, that inherit from it output messages
 * to standard output in a readable form in a multithreaded
 * application.
*/
class ThreadSafeLogger {
public:
    ThreadSafeLogger(std::mutex *streamMutex)
        : m_streamMutex(streamMutex) {}

    void printMessage(const std::string& msg) {
        if (m_streamMutex) {
            std::lock_guard<std::mutex> lock(*m_streamMutex);
            std::cout << msg << std::endl;
        }
    }

private:
    std::mutex* m_streamMutex;
};

#endif //THREADSAFELOGGER_H