#ifndef BV_ENGINE_UTIL_ASSERT_H
#define BV_ENGINE_UTIL_ASSERT_H

void assert_impl(const char *expr, const char *file, const int line);

#ifndef NDEBUG

#define ASSERT(EXPR)                                \
    do {                                            \
        if (!(EXPR))                                \
            assert_impl(#EXPR, __FILE__, __LINE__); \
    } while (0)

#define UNREACHABLE()                               \
    do {                                            \
    assert_impl("UNREACHABLE", __FILE__, __LINE__); \
    } while (0)

#else 

#define ASSERT(EXPR) 
#define UNREACHABLE()

#endif // NDEBUG 

#endif // BV_ENGINE_UTIL_ASSERT_H

