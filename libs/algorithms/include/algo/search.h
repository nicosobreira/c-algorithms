#pragma once

#include "ds/list/core.h"

typedef struct SearchResult
{
    const size_t index;
    const void *pointer_to;
    const bool did_find;
} SearchResult;

// ----------------------------------------

bool SearchResult_Check(const SearchResult *self);

size_t SearchResult_Index(const SearchResult *self);

const void *SearchResult_PointerTo(const SearchResult *self);

// ----------------------------------------

/// Binary Search on a List
/// @param list an **already sorted** list in **increasing order**
/// @param value the value to be find
SearchResult binary_search(const List *list, const void *value);
