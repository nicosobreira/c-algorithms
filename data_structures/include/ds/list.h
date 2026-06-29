#pragma once

#include <stddef.h>

/** Dynamic Array with only a data type
 */
typedef struct List
{
    void *ptr;
    size_t size;
    size_t capacity;
    size_t data_size;
} List;

List List_New(size_t size, size_t data_size);

void List_Free(List *self);

List List_WithCapacity(size_t capacity, size_t data_size);

static void *List_Get(List *self, size_t index)
{
    if (index >= self->size)
    {
        // ERROR
    }

    return self->ptr + (index * self->data_size);
}

void List_Set(List *self, size_t index, void *value);

void List_Swap(List *self, size_t index_a, size_t index_b);

void List_Append(List *self, void *value);

void List_Pop(List *self);

/*
 * List_New(size)
 * List_WithCapacity(capacity)
 * List_Get(index)
 * List_Set(index, value)
 * List_Swap(i, j)
 * List_Append(value)
 * List_Slice() ?
 */
