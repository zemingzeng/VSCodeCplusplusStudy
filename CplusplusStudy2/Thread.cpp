#include "Thread.h"
#include "Util.hpp"
using namespace mingzz;
Thread::Thread()
{
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
    return 0;
}

int Thread::stop()
{
    if (t)
    {
        t->join();
        delete t;
        t = nullptr;
    }
    return 0;
}
