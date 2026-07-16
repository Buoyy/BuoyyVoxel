#include "engine/util/file.h"

#include "engine/util/log.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool file_read_full(const char *path, char **buffer)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
    {
        LOG_ERROR("Couldn't open file '%s'", path);
        perror("");
        return false;
    }
    LOG_INFO("Opened file '%s'", path);

    LOG_INFO("Calculating file size for file '%s'", path);
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    LOG_INFO("File size for file '%s' is %zu", path, file_size);

    char *file_str = malloc(sizeof(char)*(file_size+1));
    if (file_str == NULL)
    {
        LOG_ERROR("Couldn't allocate memory for reading file '%s' into dynamic buffer", path);
        fclose(file);
        return false;
    }
    LOG_INFO("Allocated %zu bytes to read file '%s'", file_size+1, path);

    size_t bytes_read = fread(file_str, sizeof(char), file_size, file);
    if (bytes_read != file_size)
    {
        LOG_ERROR("Couldn't read file: '%s'", path);
        free(file_str);
        fclose(file);
        return false;
    }
    LOG_INFO("Read %zu bytes into buffer allocated for '%s'", bytes_read, path);

    file_str[bytes_read] = 0;
    *buffer = file_str;
    fclose(file);
    LOG_INFO("Closed file '%s'", path);

    return true;
}

void file_free(char *buffer)
{
    free(buffer);
}
