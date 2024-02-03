#include "Observer.h"

#include <iostream>


Observer::Observer(std::mutex *streamMutex) 
    : ThreadSafeLogger(streamMutex), m_msgCount(0)
{

}

void Observer::update(const std::string &msg)
{
    printMessage("Received msg: " + msg);
    ++m_msgCount;
}

size_t Observer::getMessageCount() const
{
    return m_msgCount;
}