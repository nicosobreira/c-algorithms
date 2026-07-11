#include "compare/core.h"

#include "default.h"

Compare Compare_New(CompareEquals equals, CompareLess less)
{
    return (Compare){.equals = equals, .less = less};
}

Compare Compare_New_int(void)
{
    return (Compare){.equals = int_equals, .less = int_less};
}

Compare Compare_New_double(void)
{
    return (Compare){.equals = double_equals, .less = double_less};
}
