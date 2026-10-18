#include "ds/list/core.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/allocation.h"
#include "utils/assert.h"
#include "utils/memory.h"

static void List_Resize(List *self, size_t resize)
{
    self->capacity += resize;
    void *new = must_realloc(self->view.ptr, self->view.data_size * self->capacity);

    self->view.ptr = new;
}

List List_New(size_t size, size_t data_size, Compare compare, Operations operations)
{
    ASSERT(size > 0, "The list must have a size");
    ASSERT(data_size > 0, "The list must have a data size");

    void *ptr = must_malloc(data_size * size);

    return (List){.view = ListView_New(ptr, data_size, size, compare, operations), .capacity = size};
}

void List_Free(List *self)
{
    free(self->view.ptr);

    self->view.ptr = NULL;
    self->view.size = 0;
    self->capacity = 0;
}

List List_WithCapacity(size_t capacity, size_t data_size, Compare compare, Operations operations)
{
    ASSERT(capacity > 0, "The list must have a capacity");
    ASSERT(data_size > 0, "The list must have a data size");

    const size_t size = 0;
    void *ptr = must_malloc(data_size * capacity);

    return (List){.view = ListView_New(ptr, data_size, size, compare, operations), .capacity = size};
}

List List_Load(const void *array, size_t size, size_t data_size, Compare compare, Operations operations)
{
    ASSERT(size > 0, "The list must have a size");
    ASSERT(data_size > 0, "The list must have a data size");

    List new = List_New(size, data_size, compare, operations);

    for (size_t i = 0; i < size; ++i)
    {
        List_Set(&new, i, byte_offset(array, i, data_size));
    }

    return new;
}

List ListView_LoadSlice(const ListView *view, size_t start_index, size_t end_index)
{
    ASSERT(start_index <= end_index, "start should be less or equal to end");

    ASSERT(start_index < view->size, "Index Out of Bounds");
    ASSERT(end_index < view->size, "Index Out of Bounds");

    void *new_start = ListView_Get(view, start_index);

    size_t new_size = end_index - start_index + 1;

    List new = List_Load(new_start, new_size, view->data_size, view->compare, view->operations);

    return new;
}

ListView ListView_NewSlice(const ListView *view, size_t start_index, size_t end_index)
{
    ASSERT(start_index <= end_index, "start should be less or equal to end");

    ASSERT(start_index < view->size, "Index Out of Bounds");
    ASSERT(end_index < view->size, "Index Out of Bounds");

    void *new_ptr = ListView_Get(view, start_index);

    size_t new_size = end_index - start_index + 1;

    return ListView_New(new_ptr, view->data_size, new_size, view->compare, view->operations);
}

void List_Push(List *self, void *value)
{
    const size_t resize = 10;

    if (self->view.size >= self->capacity)
    {
        List_Resize(self, resize);
    }

    self->view.size += 1;

    List_Set(self, self->view.size - 1, value);
}
