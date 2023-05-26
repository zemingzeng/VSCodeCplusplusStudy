#include "thread.h"
#include "Util.hpp"
using namespace mingzz;
Thread::Thread()
{
    Util::LOGI("Thread constructor!");
}

Thread::~Thread()
{
    Util::LOGI("Thread destructor!");
    if (t)
    {
        Thread::stop();
    }
}

int Thread::start()
{
    Util::LOGI("Thread::start()");
    return 0;
}

int Thread::stop()
{
    Util::LOGI("Thread::stop()");
    if (t)
    {
        // t->join(); //等待任务完成然后才delete
        Util::LOGI("before delete t");
        delete t;
        Util::LOGI("after delete t");
        t = nullptr;
    }
    return 0;
}
