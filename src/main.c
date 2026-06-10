#include "engine/util/log.h"

int main()
{
    LOG_INFO("Hello, BuoyyVoxel %.1f!", 2.0f);
    LOG_WARN("Don't start without a plan!", "");
    LOG_ERROR("Commit %d is incomplete!", 0);
}