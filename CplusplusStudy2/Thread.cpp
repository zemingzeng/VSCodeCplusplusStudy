#include "thread.h"
#include "Util.hpp"
using namespace mingzz;
Thread::Thread() : mpThread(nullptr)
{
    Util::LOGI("Thread constructor!");
}

Thread::~Thread()
{
    Util::LOGI("Thread destructor!");
    if (mpThread)
    {
        Thread::stop();
    }
}

int Thread::start()
{
    Util::LOGI("Thread::start()!");
    mpThread = new std::thread(&run, this); // new完，thread就自动启动了
    if (!mpThread)
    {
        Util::LOGI("new std::thread error!");
        return -1;
    }
    return 0;
}

int Thread::stop()
{
    Util::LOGI("Thread::stop()");
    if (mpThread)
    {
        Util::LOGI("before delete t");
        join(); // 等待任务完成然后才delete,
                // 会阻塞此线程直到mpThread任务处理完成然后返回
        delete mpThread;
        Util::LOGI("after delete t");
        mpThread = nullptr;
    }
    return 0;
}

void Thread::join()
{
    Util::LOGI("Thread join()!");
    if (mpThread)
    {
        if (mpThread->joinable())
            mpThread->join();
    }
}

void Thread::detach()
{
    Util::LOGI("Thread detach()!");
    if (mpThread)
    {
        if (mpThread->joinable())
            mpThread->detach();
    }
}