#ifndef DEMUXTHREAD_H
#define DEMUXTHREAD_H

#include "Thread.h"

class DemuxThread : public Thread
{
public:
    int init();
    int start();
    int stop();
    void join();
    void detach();

protected:
    void run() override;

private:
    std::string url;
};

#endif