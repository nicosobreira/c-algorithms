#pragma once

#include <stddef.h>

static inline void *byte_offset(const void *ptr, size_t index, size_t data_size)
{
    return (char *)ptr + (index * data_size);
}
