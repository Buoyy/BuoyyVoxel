#ifndef BV_ENGINE_UTIL_DYN_ARRAY_H
#define BV_ENGINE_UTIL_DYN_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct DynArray DynArray;
struct DynArray
{
    void *data;
    size_t element_size;
    size_t length;
    size_t capacity;
};

// Initialise a dynamic array of given element size. Returns true on successful initalization.
// Returns false otherwise.
bool  da_init(DynArray *da, const size_t element_size);

// Appends the given value into the given dynamic array.
void  da_append(DynArray *da, const void *value);

// Retrieves the pointer to the element at the given index in the dynamic array.
void *da_get(DynArray *da, size_t index);

// Sets the element at the given index in the dynamic array to the given value.
void  da_set(DynArray *da, size_t index, const void *value);

// Inserts the given element at the given index in the dynamic array.
void  da_insert(DynArray *da, size_t index, const void *value);

// Removes the element at the given index from the dynamic array.
void  da_remove(DynArray *da, size_t index);

// De-initialises the given dynamic array.
void  da_deinit(DynArray *da);

#endif // BV_ENGINE_UTIL_DYN_ARRAY_H