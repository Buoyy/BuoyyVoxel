#ifndef BV_ENGINE_UTIL_FILE_H
#define BV_ENGINE_UTIL_FILE_H

#include <stdbool.h>

bool file_read_full(const char *path, char **buffer);
void file_free(char *buffer);

#endif