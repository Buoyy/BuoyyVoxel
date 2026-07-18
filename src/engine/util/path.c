#include "engine/util/path.h"

#include <string.h>

const char *path_filename(const char *path)
{
    const char* filename = strrchr(path, '/');
    if (!filename) {
        filename = strrchr(path, '\\');
    }
    return filename ? filename + 1 : path;
}

