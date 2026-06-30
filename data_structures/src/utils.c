#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

void *must_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL && size > 0)
    {
        int i = fprintf(stderr, "Fatal Error: Out of memory (failed to allocate %zu bytes).\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *must_realloc(void *ptr, size_t size)

{
    void *new = realloc(ptr, size);
    if (new == NULL && size > 0)
    {
        int i = fprintf(stderr, "Fatal Error: Out of memory (failed to allocate %zu bytes).\n", size);
        exit(EXIT_FAILURE);
    }
    return new;
}
