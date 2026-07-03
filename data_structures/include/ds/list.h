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

static inline size_t List_Size(List *self)
{
    return self->size;
}

static inline bool List_IsEmpty(List *self)
{
    if (self->size == 0)
    {
        return true;
    }

    return false;
}

List List_Load(void *array, size_t size, size_t data_size);

/// Creates an copy of list from indexes start to end (inclusive)
List List_NewSlice(List *list, size_t start_index, size_t end_index);

void *List_Get(List *self, size_t index);

void List_Set(List *self, size_t index, void *value);

void List_Swap(List *self, size_t index_a, size_t index_b);

void List_Push(List *self, void *value);

void List_Pop(List *self);

// ------------------------------------------------------------

void List_Print_int(List *self);

void List_Print_float(List *self);

void List_Print_double(List *self);
