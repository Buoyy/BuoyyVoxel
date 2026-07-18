#ifndef BV_ENGINE_UTIL_DYN_ARRAY_H
#define BV_ENGINE_UTIL_DYN_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

/**
 * Represents a generic dynamic array.
 * Keeps track of number of elements, reserved space for elements and size of each element.
 */
typedef struct DynArray
{
    void *data;
    size_t element_size;
    size_t length;
    size_t capacity;
} DynArray;

/**
 * Initializes a dynamic array of given element size. 
 * Returns true on successful initalization and false otherwise.
 *
 * @param da - Pointer to the target DynArray
 * @param element_size - The size of each element in the DynArray
 */
bool  da_init(DynArray *da, const size_t element_size);

/** Appends the given value into the given dynamic array.
 *
 * @param da - Pointer to the target DynArray
 * @param value - Pointer to the value to append
 */
void  da_append(DynArray *da, const void *value);

/**
 * Retrieves the pointer to the element at the given index in the dynamic array.
 *
 * @param da - Pointer to the target DynArray
 * @param index - Index of the value in the DynArray 
 */
void *da_get(const DynArray *da, size_t index);

/**
 * Sets the element at the given index in the dynamic array to the given value.
 *
 * @param da - Pointer to the target DynArray
 * @param index - Index of the value in the DynArray
 * @param value - Pointer to the new value
*/
void  da_set(DynArray *da, size_t index, const void *value);

/** 
 * Inserts the given element at the given index in the dynamic array.
 *
 * @param da - Pointer to the target DynArray
 * @param index - Index at which to insert the value in the DynArray
 * @param value - Pointer to the value to be inserted
*/
void  da_insert(DynArray *da, size_t index, const void *value);

/**
 * Removes the element at the given index from the dynamic array.
 *
 * @param da - Pointer to the target DynArray
 * @param index - Index of the value to be removed
 */
void  da_remove(DynArray *da, size_t index);

/**
 * De-initialises the given dynamic array.
 *
 * @param da - Pointer to the target DynArray
*/
void  da_deinit(DynArray *da);

#endif // BV_ENGINE_UTIL_DYN_ARRAY_H

