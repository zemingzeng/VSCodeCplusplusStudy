#include "demuxThread.h"
#include "Util.hpp"
#include <iostream>
using namespace mingzz;

DemuxThread::DemuxThread() /*: mAVFContext(nullptr)*/
{
    memset(mAVErrorInfo, 0, sizeof(mAVErrorInfo));
}

DemuxThread::~DemuxThread()
{
}

void DemuxThread::run()
{
    Util::LOGI("DemuxThread run()!");
    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Current thread id:" << threadId << std::endl;
    int count = 0;
    while (count < 3)
    {
        Util::LOGI("DemuxThread running and count:%d", count);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        count++;
    }
}

int DemuxThread::init(const char *url)
{
    Util::LOGI("DemuxThread::init() : Url->%s!", url);
    mUrl = url;
    // mAVFContext = avformat_alloc_context();
    // if(!mAVFContext){}
    // int ret = avformat_open_input(&mAVFContext, mUrl, nullptr, nullptr);
    // av_strerror(ret, mAVErrorInfo, sizeof(mAVErrorInfo));
    return 0;
}