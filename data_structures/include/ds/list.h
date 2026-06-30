#pragma once

#include <stdbool.h>
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

static size_t List_Size(List *self)
{
    return self->size;
}

/*
static bool List_IsEmpty(List *self)
{
    if (self->size > 0)
    {
        return true;
    }

    return false;
}
*/

List List_Load(void *array, size_t size, size_t data_size);

void *List_Get(List *self, size_t index);

void List_Set(List *self, size_t index, void *value);

void List_Swap(List *self, size_t index_a, size_t index_b);

void List_Push(List *self, void *value);

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
