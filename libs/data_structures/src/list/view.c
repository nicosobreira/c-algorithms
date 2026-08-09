#include "ds/list/view.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/allocation.h"
#include "utils/assert.h"
#include "utils/memory.h"

#include "unsafe.h"

ListView ListView_New(void *ptr, size_t data_size, size_t size, Compare compare)
{
    return (ListView){
        .compare = compare,
        .data_size = data_size,
        .size = size,
        .ptr = ptr,
    };
}

void *ListView_Get(const ListView *self, size_t index)
{
    ASSERT(index < self->size, "Index Out of Bounds");

    return byte_offset(self->ptr, index, self->data_size);
}

void *ListView_GetCopy(const ListView *self, size_t index)
{
    void *copy = must_malloc(self->data_size);

    memcpy(copy, ListView_Get(self, index), self->data_size);

    return copy;
}

void ListView_Set(ListView *self, size_t index, void *value)
{
    ASSERT(index < self->size, "Index Out of Bounds");

    memcpy(ListView_Get(self, index), value, self->data_size);
}

void ListView_Swap(ListView *self, size_t index_a, size_t index_b)
{
    ASSERT(index_a < self->size, "Index Out of Bounds");
    ASSERT(index_b < self->size, "Index Out of Bounds");

    void *temp = LIST_VIEW_GET_STACK_COPY(self, index_a);
    void *a = ListView_Get(self, index_a);
    void *b = ListView_Get(self, index_b);

    memcpy(a, b, self->data_size);
    memcpy(b, temp, self->data_size);
}

void ListView_Pop(ListView *self)
{
    ASSERT(self->size != 0, "The list is empty");

    self->size -= 1;
}
