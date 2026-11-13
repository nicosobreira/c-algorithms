#pragma once

#include "core.h"

#include "compare/defaults.h"
#include "operations/defaults.h"

static inline Heap Heap_WithCapacity_int(size_t capacity)
{
    return Heap_WithCapacity(capacity, sizeof(int), Compare_New_int(), Operations_New_int());
}

static inline Heap Heap_Load_int(const int *array, size_t size)
{
    return Heap_Load(array, size, sizeof(int), Compare_New_int(), Operations_New_int());
}

// ------------------------------------------------------------

static inline Heap Heap_WithCapacity_double(size_t capacity)
{
    return Heap_WithCapacity(capacity, sizeof(double), Compare_New_double(), Operations_New_double());
}

static inline Heap Heap_Load_double(const double *array, size_t size)
{
    return Heap_Load(array, size, sizeof(double), Compare_New_double(), Operations_New_double());
}
