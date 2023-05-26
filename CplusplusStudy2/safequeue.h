#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Util.hpp"

using namespace mingzz;

template <typename T>
class SafeQueue
{
public:
    SafeQueue();
    ~SafeQueue();
    void abort();
    int push(T t);
    int pop(T& t,int timeOut=0);

private:
    int mAbort;
    std::queue<T> mQueue;
    std::mutex mMutex;
    std::condition_variable mCondition;
};

#endif
