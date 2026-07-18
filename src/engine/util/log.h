#ifndef BV_ENGINE_UTIL_LOG_H
#define BV_ENGINE_UTIL_LOG_H

#define LOG_INFO(MSG, ...) log_impl(LOG_LEVEL_INFO, MSG, ##__VA_ARGS__)
#define LOG_WARN(MSG, ...) log_impl(LOG_LEVEL_WARN, MSG, ##__VA_ARGS__)
#define LOG_ERROR(MSG, ...) log_impl(LOG_LEVEL_ERROR, MSG, ##__VA_ARGS__)

typedef enum LogLevel
{
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
} LogLevel;

void log_impl(LogLevel log_level, const char *message, ...) __attribute__((format(printf, 2, 3)));

#endif // BV_ENGINE_UTIL_LOG_H

