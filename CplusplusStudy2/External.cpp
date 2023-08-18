#include "Util.hpp"
void externalMethod();
static void staticInternalMethod();
void externalMethod()
{
    mingzz::Util::LOGI("External.cpp void externalMethod()!");
}

void staticExternalMethod()
{
    mingzz::Util::LOGI("External.cpp void staticExternalMethod()!");
}

namespace
{
    void anonymousNameSpaceMethod();
    void anonymousNameSpaceMethod()
    {
        mingzz::Util::LOGI("External.cpp void anonymousNameSpaceMethod()!");
    }
}

//extern int externalNumber;//extern成员在使用处声明时必须带关键字extern,但是在声明定义处可以不用，可以直接int externalNumber = 111;
int externalNumber = 111;