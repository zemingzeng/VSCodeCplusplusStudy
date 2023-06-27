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
