#include "demuxThread.h"
#include "Util.hpp"
#include <iostream>
using namespace mingzz;

void DemuxThread::run()
{
    Util::LOGI("DemuxThread run()!");
    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Current thread id:" << threadId << std::endl;
    int count = 0;
    while (count < 3)
    {
        Util::LOGI("DemuxThread running and count:%d", count);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        count++;
    }
}

void DemuxThread::join()
{
    Util::LOGI("DemuxThread join()!");
    if (t)
    {
        t->join();
    }
}

void DemuxThread::detach()
{
      Util::LOGI("DemuxThread detach()!");
    if (t)
    {
        t->detach();
    } 
}

int DemuxThread::init()
{
    Util::LOGI("DemuxThread init()!");
    return 0;
}
int DemuxThread::start()
{
    Util::LOGI("DemuxThread::start()!");
    t = new std::thread(&DemuxThread::run, this); // new完，thread就自动启动了
    if (!Thread::t)
    {
        Util::LOGI("new std::thread error!");
        return -1;
    }
    return 0;
}

int DemuxThread::stop()
{
    Util::LOGI("DemuxThread::stop()!");
    Thread::stop();
    return 0;
}