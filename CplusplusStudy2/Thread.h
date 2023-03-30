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
    virtual void run() = 0;

protected:
    std::thread *t = nullptr;
};

#endif
