#include "operations/core.h"

Operations Operations_New(size_t data_size, OperationsFunctions functions)
{
    return (Operations){
        .data_size = data_size,
        .functions = functions,
    };
}

void Operations_Add(const Operations *self, void *result, const void *a, const void *b)
{
    self->functions.add(result, a, b);
}

void Operations_Subtract(const Operations *self, void *result, const void *a, const void *b)
{
    self->functions.subtract(result, a, b);
}

void Operations_Multiply(const Operations *self, void *result, const void *a, const void *b)
{
    self->functions.multiply(result, a, b);
}

void Operations_Divide(const Operations *self, void *result, const void *a, const void *b)
{
    self->functions.divide(result, a, b);
}
