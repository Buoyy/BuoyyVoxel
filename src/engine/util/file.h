#ifndef BV_ENGINE_UTIL_FILE_H
#define BV_ENGINE_UTIL_FILE_H

#include <stdbool.h>

/**
 * Reads an entire file at the given file path into the given buffer.
 * Uses dynamic memory allocation.
 *
 * @param[in] path - The file path of the file to read
 * @param[out] buffer - The buffer to read the file to
 *
 * @return `true` if the file was read successfully and `false` otherwise.
 */
bool file_read_full(const char *path, char **buffer);

/**
 * Frees the buffer where an entire file was read.
 * Uses stdlib's `free()`.
 *
 * @param[in] buffer - The buffer where an entire file was read.
 */
void file_free(char *buffer);

#endif // BV_ENGINE_UTIL_FILE_H

