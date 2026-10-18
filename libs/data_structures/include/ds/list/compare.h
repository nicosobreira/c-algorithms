#pragma once

#include "core.h"
#include "view.h"

static inline bool ListView_Compare_Equals(const ListView *self, const void *a, const void *b)
{
    return Compare_Equals(&self->compare, a, b);
}

static inline bool ListView_Compare_EqualsAt(const ListView *self, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    return Compare_Equals(&self->compare, a, b);
}

static inline bool ListView_Compare_Less(const ListView *self, const void *a, const void *b)
{
    return Compare_Less(&self->compare, a, b);
}

static inline bool ListView_Compare_LessAt(const ListView *self, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    return Compare_Less(&self->compare, a, b);
}

static inline bool ListView_Compare_Greater(const ListView *self, const void *a, const void *b)
{
    return Compare_Greater(&self->compare, a, b);
}

static inline bool ListView_Compare_GreaterAt(const ListView *self, size_t i, size_t j)
{
    const void *a = ListView_Get(self, i);
    const void *b = ListView_Get(self, j);

    return Compare_Greater(&self->compare, a, b);
}

// ------------------------------------------------------------

static inline bool List_Compare_Equals(const List *self, const void *a, const void *b)
{
    return ListView_Compare_Equals(&self->view, a, b);
}

static inline bool List_Compare_Less(const List *self, const void *a, const void *b)
{
    return ListView_Compare_Less(&self->view, a, b);
}

static inline bool List_Compare_Greater(const List *self, const void *a, const void *b)
{
    return ListView_Compare_Greater(&self->view, a, b);
}
