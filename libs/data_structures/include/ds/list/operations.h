#pragma once

#include "view.h"

static inline void ListView_Operations_Add(const ListView *self, void *result, const void *a, const void *b)
{
    Operations_Add(&self->operations, result, a, b);
}

static inline void ListView_Operations_AddAt(const ListView *self, void *result, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    Operations_Add(&self->operations, result, a, b);
}

static inline void ListView_Operations_Subtract(const ListView *self, void *result, const void *a, const void *b)
{
    Operations_Subtract(&self->operations, result, a, b);
}

static inline void ListView_Operations_SubtractAt(const ListView *self, void *result, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    Operations_Subtract(&self->operations, result, a, b);
}

static inline void ListView_Operations_Multiply(const ListView *self, void *result, const void *a, const void *b)
{
    Operations_Multiply(&self->operations, result, a, b);
}

static inline void ListView_Operations_MultiplyAt(const ListView *self, void *result, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    Operations_Multiply(&self->operations, result, a, b);
}

static inline void ListView_Operations_Divide(const ListView *self, void *result, const void *a, const void *b)
{
    Operations_Divide(&self->operations, result, a, b);
}

static inline void ListView_Operations_DivideAt(const ListView *self, void *result, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    Operations_Divide(&self->operations, result, a, b);
}
