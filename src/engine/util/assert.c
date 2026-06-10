#include "engine/util/assert.h"

#include "engine/util/log.h"
#include <string.h>
#include <stdlib.h>

static const char *get_filename(const char *path)
{
    const char* filename = strrchr(path, '/');
    if (!filename) {
        filename = strrchr(path, '\\');
    }
    return filename ? filename + 1 : path;
}

void assert_impl(const char *expr, const char *file, const int line)
{
    LOG_ERROR("Assertion failed: %s (%s:%d)", expr, get_filename(file), line);
    abort();
}