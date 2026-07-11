#include "algo/search.h"

#include "utils/assert.h"

bool SearchResult_Check(const SearchResult *self)
{
    return self->did_find;
}

size_t SearchResult_Index(const SearchResult *self)
{
    ASSERT(self->did_find, "The result was unsuccessful, can't use the index");

    return self->index;
}

void *SearchResult_PointerTo(const SearchResult *self)
{
    ASSERT(self->did_find, "The result was unsuccessful, can't use the pointer to");

    return self->pointer_to;
}
