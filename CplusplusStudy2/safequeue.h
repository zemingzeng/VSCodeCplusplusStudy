#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SafeQueue
{
public:
    SafeQueue();

private:
    queue<T> mQueue;
    std::mutex mMutex;
    std::condition_variable mCondition;
}

#endif
