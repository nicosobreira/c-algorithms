#pragma once

#include "compare/core.h"

#define EQUALS(a, b, type)      \
    type va = *(const type *)a; \
    type vb = *(const type *)b; \
                                \
    return va == vb;

#define LESS(a, b, type)        \
    type va = *(const type *)a; \
    type vb = *(const type *)b; \
                                \
    return va < vb;

/// Equal
/// @return true if a == b, false otherwise
bool int_equals(COMPARE_FUNC_ARGS);

/// Less
/// @return true if a < b, false otherwise
bool int_less(COMPARE_FUNC_ARGS);

// ----------------------------------------

/// Equal
/// @return true if a == b, false otherwise
bool double_equals(COMPARE_FUNC_ARGS);

/// Less
/// @return true if a < b, false otherwise
bool double_less(COMPARE_FUNC_ARGS);
