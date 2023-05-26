#include "safequeue.h"

template <typename T>
SafeQueue<T>::SafeQueue()
{
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{
}

template <typename T>
void SafeQueue<T>::abort()
{
    Util::LOGI(" SafeQueue<T>::abort()");
    mAbort = 1;
    mCondition.notify_all();
}

template <typename T>
int SafeQueue<T>::push(T t)
{
    std::lock_guard<std::mutex> lock(mMutex); // 获取锁
    if (1 == abort)
    {
        Util::LOGI("abort == 1 can not push!");
        return -1;
    }
    mQueue.push(t);
    mCondition.notify_one(); // 尝试唤醒 wait
    return 0;
}

template <typename T>
int SafeQueue<T>::pop(T &t, int timeOut /*milliseconds*/)
{
    std::lock_guard<std::mutex> lock(mMutex);
    if (mQueue.empty)
    {
        // 等待唤醒或者等待push
        mCondition.wait_for(lock, std::chrono::milliseconds(timeOut),
                            [this]() -> bool
                            {
                                return !mQueue.empty | mAbort; // 等待期间，会判断此条件，返回true会立马返回
                                                               // 继续运行，否则，还会wait，等待下一次notify
                            });
    }
    return 0;
}
