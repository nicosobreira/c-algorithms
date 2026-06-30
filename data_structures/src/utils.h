#pragma once

#include <stddef.h>

void *must_malloc(size_t size);

void *must_realloc(void *ptr, size_t size);
