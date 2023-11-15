#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H

#include "Thread.h"

class DemuxThread : public Thread
{
public:
    int init(const char *);
    DemuxThread();
    ~DemuxThread();

private:
    void run() override;

private:
    char mAVErrorInfo[256];
    std::string mUrl;
    // AVPacketQueue *mVQueue; // video packet queue
    // AVPacketQueue *mAQueue; // audio packet queue
    // AVFormatContext* mAVFContext;
};

#endif