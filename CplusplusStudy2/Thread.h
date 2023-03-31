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

private:

protected:
    std::thread *t = nullptr;
    virtual void run() = 0;
};

#endif
