#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H

#include "Thread.h"

class DemuxThread : public Thread
{
public:
    void run() override;
};

#endif