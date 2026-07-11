#pragma once

#include "ds/list.h"

typedef bool (*EqualsFunc)(const void *a, const void *b);

typedef struct SearchResult
{
    const bool did_find;

    const size_t index;

    /// Pointer to the value found
    const void *pointer_to;
} SearchResult;

// ----------------------------------------

bool SearchResult_Check(const SearchResult *self);

size_t SearchResult_Index(const SearchResult *self);

void *SearchResult_PointerTo(const SearchResult *self);

// ----------------------------------------

/// Binary Search on a List
/// @param list an **already sorted** list
/// @param value the value to be find
SearchResult binary_search(const List *list, const void *value, EqualsFunc equals);

// ----------------------------------------

bool int_equals(const void *a, const void *b);

bool float_equals(const void *a, const void *b);

bool double_equals(const void *a, const void *b);
