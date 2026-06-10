#include "engine/util/log.h"
#include "engine/util/assert.h"

int main()
{
    LOG_INFO("Hello, BuoyyVoxel %.1f!", 2.0f);

    ASSERT(1 == 1);

    LOG_WARN("Don't start without a plan!", "");

    // Uncomment to test assertions
    // ASSERT(0 == 1);

    LOG_INFO("Commit %d is complete!", 0);
}