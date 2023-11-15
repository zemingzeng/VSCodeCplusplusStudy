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
    bool ret = true;
    if (mQueue.empty())
    {
        // 等待唤醒或者等待push
        ret = mCondition.wait_for(lock, std::chrono::milliseconds(timeOut),
                                  [this]() -> bool
                                  {
                                      return !mQueue.empty() | mAbort; // 判断此条件，返回true会继续执行下面的代码
                                                                       // 否则，还会wait，等待下一次notify
                                  });
        // 取到数据
    }
    return true == ret ? 0 : -1;
}
