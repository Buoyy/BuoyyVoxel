#include <engine/util/dyn_array.h>

#include <engine/util/log.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define DA_INIT_CAP 4

static bool da_grow(DynArray *da)
{
    void *new_data = realloc(da->data, 2 * da->capacity * da->element_size);
    if (new_data == NULL)
    {
        LOG_ERROR("Couldn't reallocate memory for DynArray");
        return false;
    }

    da->capacity *= 2;
    da->data = new_data;
    return true;
}

bool da_init(DynArray *da, const size_t element_size)
{
    da->data = NULL;
    da->element_size = element_size;
    da->length = 0;
    da->capacity = DA_INIT_CAP;

    da->data = malloc(DA_INIT_CAP * element_size);
    if (da->data == NULL)
    {
        LOG_ERROR("Couldn't reallocate memory for DynArray");
        return false;
    }

    return true;
}

void da_append(DynArray *da, const void *value)
{
    if (da->length >= da->capacity)
    {
        if (!da_grow(da))
        {
            return;
        }
    }

    char *p_end = (char *)da->data + da->length * da->element_size;
    memcpy(p_end, value, da->element_size);
    da->length++;
}

void *da_get(const DynArray *da, size_t index)
{
    if (index >= da->length)
    {
        LOG_ERROR("Index out of bounds");
        return NULL;
    }

    return (char*)da->data + index * da->element_size;
}


void da_set(DynArray *da, size_t index, const void *value)
{
    void *p_element = da_get(da, index);
    if (p_element == NULL) return;

    memcpy(p_element, value, da->element_size);
}

void da_insert(DynArray *da, size_t index, const void *value)
{
    if (index > da->length)
    {
        LOG_ERROR("Index out of bounds");
        return;
    }

    if (da->length >= da->capacity)
    {
        if (!da_grow(da))
        {
            return;
        }
    }

    char *p_next_element = (char *)da->data + (index + 1) * da->element_size; 
    char *p_curr_element = (char *)da->data + index * da->element_size; 
    size_t bytes_to_move = (da->length - index) * da->element_size;
    memmove(p_next_element, p_curr_element, bytes_to_move);
    memcpy(p_curr_element, value, da->element_size);
    da->length++;
}

void da_remove(DynArray *da, size_t index)
{
    if (index >= da->length)
    {
        LOG_ERROR("Index out of bounds");
        return;
    }

    char *p_curr_element = (char*)da->data + index * da->element_size;
    char *p_next_element  = (char*)da->data + (index + 1) * da->element_size;
    size_t bytes_to_move = (da->length - index - 1) * da->element_size;

    memmove(p_curr_element, p_next_element, bytes_to_move);
    da->length--;
}

void da_deinit(DynArray *da)
{
    free(da->data);

    da->data = NULL;
    da->length = 0;
    da->capacity = 0;
}

