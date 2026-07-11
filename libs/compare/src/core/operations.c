#include "compare/core.h"

#include "utils/assert.h"

bool Compare_Equals(const Compare *self, COMPARE_FUNC_ARGS)
{
    ASSERT(self->equals != NULL, "Please, define the `equals` function pointer in `Compare_New`");

    return self->equals(a, b);
}

bool Compare_Less(const Compare *self, COMPARE_FUNC_ARGS)
{
    ASSERT(self->equals != NULL, "Please, define the `less` function pointer in `Compare_New`");

    return self->less(a, b);
}

bool Compare_LessEquals(const Compare *self, COMPARE_FUNC_ARGS)
{
    return (bool)(Compare_Less(self, a, b) || Compare_Equals(self, a, b));
}

bool Compare_NotEqual(const Compare *self, COMPARE_FUNC_ARGS)
{
    return (bool)!Compare_Equals(self, a, b);
}

bool Compare_Greater(const Compare *self, COMPARE_FUNC_ARGS)
{
    return (bool)!Compare_LessEquals(self, a, b);
}

bool Compare_GreaterEquals(const Compare *self, COMPARE_FUNC_ARGS)
{
    return (bool)!Compare_Less(self, a, b);
}
