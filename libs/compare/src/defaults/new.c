#include "compare/defaults.h"

#include "compare_funcs.h"

Compare Compare_New_int(void)
{
    return Compare_New(compare_int);
}

Compare Compare_New_double(void)
{
    return Compare_New(compare_double);
}
