#pragma once

#include <stdbool.h>

#define COMPARE_FUNC_ARGS const void *a, const void *b
typedef bool (*CompareFunc)(COMPARE_FUNC_ARGS);

/// Equals
typedef CompareFunc CompareEquals;

/// Less
typedef CompareFunc CompareLess;

/// Greater
typedef CompareFunc CompareLessEquals;

typedef struct Compare
{
    const CompareEquals equals;
    const CompareLess less;
} Compare;

Compare Compare_New(CompareEquals equals, CompareLess less);

Compare Compare_New_int(void);
Compare Compare_New_double(void);

bool Compare_Equals(const Compare *self, const void *a, const void *b);

bool Compare_Less(const Compare *self, const void *a, const void *b);

bool Compare_LessEquals(const Compare *self, const void *a, const void *b);

bool Compare_NotEqual(const Compare *self, const void *a, const void *b);

bool Compare_Greater(const Compare *self, const void *a, const void *b);

bool Compare_GreaterEquals(const Compare *self, const void *a, const void *b);
