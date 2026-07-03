#pragma once

#include <stdbool.h>

#include "ds/list.h"

#define COMPARE_FUNC_ARGS const void *a, const void *b
typedef bool (*CompareFunc)(COMPARE_FUNC_ARGS);

// ----------------------------------------

void merge_sort(List *p_list, CompareFunc cmp);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool int_le(COMPARE_FUNC_ARGS);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool int_ge(COMPARE_FUNC_ARGS);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool float_le(COMPARE_FUNC_ARGS);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool float_ge(COMPARE_FUNC_ARGS);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool double_le(COMPARE_FUNC_ARGS);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool double_ge(COMPARE_FUNC_ARGS);
