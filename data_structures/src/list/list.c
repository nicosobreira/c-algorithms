#include "ds/list.h"

#include <stdlib.h>
#include <string.h>

static void List_Resize(List *self, size_t new_capacity)
{
    void *new = realloc(self->ptr, self->data_size * new_capacity);
    if (new == NULL)
    {
        // ERROR
        return;
    }

    self->ptr = new;
    self->capacity = new_capacity;
}

List List_New(size_t size, size_t data_size)
{
    List new;

    new.size = size;
    new.data_size = data_size;
    new.capacity = size;

    new.ptr = malloc(new.data_size * new.capacity);

    if (new.ptr == NULL)
    {
        // ERROR
    }

    return new;
}

void List_Free(List *self)
{
    free(self->ptr);

    *self = (List){0};
}

List List_WithCapacity(size_t capacity, size_t data_size)
{
    List new;

    new.size = 0;
    new.data_size = data_size;
    new.capacity = capacity;

    new.ptr = malloc(new.data_size * new.capacity);

    if (new.ptr == NULL)
    {
        // ERROR
    }

    return new;
}

void List_Set(List *self, size_t index, void *value)
{
    if (index >= self->size)
    {
        // ERROR
        return;
    }

    memcpy(List_Get(self, index), value, self->data_size);
}

void List_Swap(List *self, size_t index_a, size_t index_b)
{
    if (index_a >= self->size || index_b >= self->size)
    {
        // ERROR
        return;
    }
    void *temp = List_Get(self, index_a);

    void **pp = &self->ptr;
    pp[index_a] = pp[index_b];

    pp[index_b] = temp;
}

void List_Append(List *self, void *value)
{
    const size_t resize = 10;

    if (self->size >= self->capacity)
    {
        List_Resize(self, self->capacity + resize);
    }

    List_Set(self, self->size, value);

    self->size += 1;
}

void List_Pop(List *self)
{
    if (self->size == 0)
    {
        // ERROR
        return;
    }

    self->size -= 1;
}
