#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H

#include "Thread.h"

class DemuxThread : public Thread
{
public:
    DemuxThread();
    ~DemuxThread();
    int init(const char *);
    void stop();

private:
    void run() override;

private:
    int mAbort;
    char mAVErrorInfo[256];
    std::string mUrl;
    // AVPacketQueue *mVQueue; // video packet queue
    // AVPacketQueue *mAQueue; // audio packet queue
    // AVFormatContext* mAVFContext;
    int mAudioIndex;
    int mVideoIndex;
};

#endif