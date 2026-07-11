#pragma once

#include <stdbool.h>

#include "ds/list.h"

#define COMPARE_FUNC_ARGS const void *a, const void *b
typedef bool (*CompareFunc)(COMPARE_FUNC_ARGS);

// ----------------------------------------

void merge_sort(List *p_list, CompareFunc cmp);

void insertion_sort(List *list, CompareFunc cmp);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool int_increasing(COMPARE_FUNC_ARGS);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool int_decreasing(COMPARE_FUNC_ARGS);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool float_increasing(COMPARE_FUNC_ARGS);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool float_decreasing(COMPARE_FUNC_ARGS);

// ----------------------------------------

/// Less Equal
/// @return true if a <= b, false otherwise
bool double_increasing(COMPARE_FUNC_ARGS);

/// Greater Equal
/// @return true if a >= b, false otherwise
bool double_decreasing(COMPARE_FUNC_ARGS);
