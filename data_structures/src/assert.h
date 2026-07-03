#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(condition, ...)                                                                          \
    do                                                                                                  \
    {                                                                                                   \
        if (!(condition))                                                                               \
        {                                                                                               \
            (void)fprintf(stderr, "\n[ASSERTION FAILED]\n");                                            \
            (void)fprintf(stderr, "Condition: %s\n", #condition);                                       \
            (void)fprintf(stderr, "Location:  %s:%d in function %s()\n", __FILE__, __LINE__, __func__); \
            (void)fprintf(stderr, "Message:   " __VA_ARGS__);                                           \
            (void)fprintf(stderr, "\n\n");                                                              \
            abort();                                                                                    \
        }                                                                                               \
    } while (0)
