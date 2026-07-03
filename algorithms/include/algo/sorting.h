#pragma once

#include <stdbool.h>

#include "ds/list.h"

void merge_sort(List *p_list, bool (*cmp)(const void *a, const void *b));

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool int_le(const void *a, const void *b);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool int_ge(const void *a, const void *b);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool float_le(const void *a, const void *b);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool float_ge(const void *a, const void *b);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool double_le(const void *a, const void *b);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool double_ge(const void *a, const void *b);
