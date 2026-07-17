#include "utils/allocation.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils/assert.h"

void *must_malloc(size_t size)
{
    ASSERT(size > 0, "Can't allocate with size equal 0");

    void *ptr = malloc(size);

    ASSERT(ptr != NULL, "Out of memory");

    return ptr;
}

void *must_realloc(void *ptr, size_t size)
{
    void *new = realloc(ptr, size);

    ASSERT(new != NULL, "Out of memory");

    return new;
}
