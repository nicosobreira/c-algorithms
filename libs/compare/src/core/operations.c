#include "compare/core.h"

bool Compare_Equals(const Compare *self, const void *a, const void *b)
{
    return self->cmp(a, b) == 0;
}

bool Compare_Less(const Compare *self, const void *a, const void *b)
{
    return self->cmp(a, b) < 0;
}

bool Compare_LessEquals(const Compare *self, const void *a, const void *b)
{
    return (bool)(Compare_Less(self, a, b) || Compare_Equals(self, a, b));
}

bool Compare_NotEqual(const Compare *self, const void *a, const void *b)
{
    return (bool)!Compare_Equals(self, a, b);
}

bool Compare_Greater(const Compare *self, const void *a, const void *b)
{
    return self->cmp(a, b) > 0;
}

bool Compare_GreaterEquals(const Compare *self, const void *a, const void *b)
{
    return (bool)!Compare_Less(self, a, b);
}
