#include "ds/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/allocation.h"
#include "utils/assert.h"
#include "utils/memory.h"

#include "unsafe.h"

static void List_Resize(List *self, size_t resize)
{
    self->capacity += resize;
    void *new = must_realloc(self->ptr, self->data_size * self->capacity);

    self->ptr = new;
}

List List_New(size_t size, size_t data_size, Compare compare)
{
    List new = {.data_size = data_size, .compare = compare};

    new.ptr = must_malloc(data_size * size);

    new.size = size;
    new.capacity = size;

    return new;
}

void List_Free(List *self)
{
    free(self->ptr);

    self->ptr = NULL;
    self->size = 0;
    self->capacity = 0;
}

List List_WithCapacity(size_t capacity, size_t data_size, Compare compare)
{
    List new = {.data_size = data_size, .compare = compare};

    new.size = 0;
    new.capacity = capacity;

    new.ptr = must_malloc(new.data_size * new.capacity);

    return new;
}

List List_Load(const void *array, size_t size, size_t data_size, Compare compare)
{
    List new = List_New(size, data_size, compare);

    for (size_t i = 0; i < size; ++i)
    {
        List_Set(&new, i, byte_offset(array, i, data_size));
    }

    return new;
}

List List_NewSlice(const List *list, size_t start_index, size_t end_index)
{
    ASSERT(start_index <= end_index, "start should be less or equal to end");

    ASSERT(start_index < list->size, "Index Out of Bounds");
    ASSERT(end_index < list->size, "Index Out of Bounds");

    void *new_start = List_Get(list, start_index);

    // Because we are dealing with indexes, we have to sum 1.
    // If both end_index and start_index are equal, say to 3, than, 3 - 3 + 1 = 1.
    size_t new_size = end_index - start_index + 1;

    List new = List_Load(new_start, new_size, list->data_size, list->compare);

    return new;
}

void *List_Get(const List *self, size_t index)
{
    ASSERT(index < self->size, "Index Out of Bounds");

    return byte_offset(self->ptr, index, self->data_size);
}

void *List_GetCopy(const List *self, size_t index)
{
    void *copy = malloc(self->data_size);

    ASSERT(copy != NULL, "Out of Memory");

    memcpy(copy, List_Get(self, index), self->data_size);

    return copy;
}

void List_Set(List *self, size_t index, void *value)
{
    ASSERT(index < self->size, "Index Out of Bounds");

    memcpy(List_Get(self, index), value, self->data_size);
}

void List_Swap(List *self, size_t index_a, size_t index_b)
{
    ASSERT(index_a < self->size, "Index Out of Bounds");
    ASSERT(index_b < self->size, "Index Out of Bounds");

    void *temp = LIST_GET_STACK_COPY(self, index_a);
    void *a = List_Get(self, index_a);
    void *b = List_Get(self, index_b);

    memcpy(a, b, self->data_size);
    memcpy(b, temp, self->data_size);
}

void List_Push(List *self, void *value)
{
    const size_t resize = 10;

    if (self->size >= self->capacity)
    {
        List_Resize(self, resize);
    }

    self->size += 1;

    List_Set(self, self->size - 1, value);
}

void List_Pop(List *self)
{
    ASSERT(self->size != 0, "The list is empty");

    self->size -= 1;
}
