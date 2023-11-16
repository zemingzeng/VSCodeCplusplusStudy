#ifndef THREAD_H
#define THREAD_H

#include <thread>
class Thread
{
public:
    Thread();
    ~Thread();
    int start();
    void join();
    void detach();
    int stop();

private:
    virtual void run() = 0;

private:
    std::thread *mpThread;
};

#endif
