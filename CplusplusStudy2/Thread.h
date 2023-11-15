#ifndef THREAD_H
#define THREAD_H

#include <thread>
class Thread
{
public:
    Thread();
    ~Thread();
    int start();
    int stop();
    void join();
    void detach();

private:
    virtual void run() = 0;

private:
    int mAbort;
    std::thread *mpThread;
};

#endif
