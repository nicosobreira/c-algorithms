#include "compare/core.h"

#include "utils/assert.h"

bool Compare_Equals(const Compare *self, const void *a, const void *b)
{
    ASSERT(self->equals != NULL, "Please, define the `equals` function pointer in `Compare_New`");

    return self->equals(a, b);
}

bool Compare_Less(const Compare *self, const void *a, const void *b)
{
    ASSERT(self->equals != NULL, "Please, define the `less` function pointer in `Compare_New`");

    return self->less(a, b);
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
    return (bool)!Compare_LessEquals(self, a, b);
}

bool Compare_GreaterEquals(const Compare *self, const void *a, const void *b)
{
    return (bool)!Compare_Less(self, a, b);
}
