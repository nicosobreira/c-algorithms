#pragma once

#include "core.h"

#include "ds/list/compare.h"

static inline bool Heap_Compare_Equals(const Heap *self, const void *a, const void *b)
{
    return List_Compare_Equals(&self->list, a, b);
}

static inline bool Heap_Compare_EqualsAt(const Heap *self, size_t i, size_t j)
{
    const void *a = Heap_Get(self, i);
    const void *b = Heap_Get(self, j);

    return List_Compare_Equals(&self->list, a, b);
}

static inline bool Heap_Compare_Less(const Heap *self, const void *a, const void *b)
{
    return List_Compare_Less(&self->list, a, b);
}

static inline bool Heap_Compare_LessAt(const Heap *self, size_t i, size_t j)
{
    const void *a = Heap_Get(self, i);
    const void *b = Heap_Get(self, j);

    return List_Compare_Less(&self->list, a, b);
}

static inline bool Heap_Compare_Greater(const Heap *self, const void *a, const void *b)
{
    return List_Compare_Greater(&self->list, a, b);
}

static inline bool Heap_Compare_GreaterAt(const Heap *self, size_t i, size_t j)
{
    const void *a = Heap_Get(self, i);
    const void *b = Heap_Get(self, j);

    return List_Compare_Greater(&self->list, a, b);
}

static inline bool Heap_Compare_GreaterEqualAt(const Heap *self, size_t i, size_t j)
{
    const void *a = Heap_Get(self, i);
    const void *b = Heap_Get(self, j);

    return Compare_GreaterEqual(&self->list.view.compare, a, b);
}
