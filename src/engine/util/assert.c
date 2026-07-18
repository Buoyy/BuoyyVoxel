#include "engine/util/assert.h"

#include "engine/util/log.h"
#include "engine/util/path.h"
#include <stdlib.h>

void assert_impl(const char *expr, const char *file, const int line)
{
    LOG_ERROR("Assertion failed: %s (%s:%d)", expr, path_filename(file), line);
    abort();
}

