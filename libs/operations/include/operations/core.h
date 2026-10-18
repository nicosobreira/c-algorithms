#pragma once

#include <stddef.h>

typedef void (*OperationFunc)(void *result, const void *a, const void *b);

typedef struct OperationsFunctions
{
    OperationFunc add;
    OperationFunc subtract;
    OperationFunc multiply;
    OperationFunc divide;
} OperationsFunctions;

typedef struct Operations
{
    OperationsFunctions functions;
    size_t data_size;
} Operations;

Operations Operations_New(size_t data_size, OperationsFunctions functions);

void Operations_Add(const Operations *self, void *result, const void *a, const void *b);

void Operations_Subtract(const Operations *self, void *result, const void *a, const void *b);

void Operations_Multiply(const Operations *self, void *result, const void *a, const void *b);

void Operations_Divide(const Operations *self, void *result, const void *a, const void *b);
