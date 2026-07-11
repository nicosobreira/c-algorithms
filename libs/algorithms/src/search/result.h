#pragma once

#include "algo/search.h"

static inline SearchResult SearchResult_Found(size_t index, const void *pointer_to)
{
    return (SearchResult){.did_find = true, .index = index, .pointer_to = pointer_to};
}

static inline SearchResult SearchResult_NotFound(void)
{
    return (SearchResult){.did_find = false, .index = 0, .pointer_to = 0};
}
