#include "compare/core.h"

#include "utils/assert.h"

Compare Compare_New(CompareFunc cmp)
{
    ASSERT(cmp != NULL, "Compare function can't be NULL");

    return (Compare){.cmp = cmp};
}
