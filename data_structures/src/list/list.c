#include "ds/list.h"
#include "../utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void out_of_bounds(void)
{
    int i = fprintf(stderr, "ERROR: Index Out of Bounds.\n");
    exit(EXIT_FAILURE);
}

static void List_Resize(List *self, size_t resize)
{
    self->capacity += resize;
    void *new = must_realloc(self->ptr, self->data_size * self->capacity);

    self->ptr = new;
}

List List_New(size_t size, size_t data_size)
{
    List new = {0};
    new.ptr = must_malloc(data_size * size);

    new.size = size;
    new.data_size = data_size;
    new.capacity = size;

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

    new.ptr = must_malloc(new.data_size * new.capacity);

    return new;
}

List List_Load(void *array, size_t size, size_t data_size)
{
    List new = List_New(size, data_size);

    for (size_t i = 0; i < size; ++i)
    {
        List_Set(&new, i, array + (i * data_size));
    }

    return new;
}

void *List_Get(List *self, size_t index)
{
    if (index >= self->size)
    {
        out_of_bounds();
    }

    return self->ptr + (index * self->data_size);
}

void List_Set(List *self, size_t index, void *value)
{
    if (index >= self->size)
    {
        out_of_bounds();
    }

    memcpy(List_Get(self, index), value, self->data_size);
}

void List_Swap(List *self, size_t index_a, size_t index_b)
{
    if (index_a >= self->size || index_b >= self->size)
    {
        out_of_bounds();
    }

    char temp[self->data_size];
    void *a = List_Get(self, index_a);
    void *b = List_Get(self, index_b);

    memcpy(temp, a, self->data_size);
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
    if (self->size == 0)
    {
        out_of_bounds();
    }

    self->size -= 1;
}
