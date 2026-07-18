#include "engine/util/log.h"

#include <stdio.h>
#include <stdarg.h>

void log_impl(LogLevel log_level, const char *message, ...)
{
    switch (log_level) 
    {
        case LOG_LEVEL_INFO:
            printf("[INFO] ");
            break;
        case LOG_LEVEL_WARN:
            printf("[WARN] ");
            break;
        case LOG_LEVEL_ERROR:
            printf("[ERROR] ");
            break;
    }

    va_list params;
    va_start(params, message);
    vprintf(message, params);
    va_end(params);
    printf("\n");
}

