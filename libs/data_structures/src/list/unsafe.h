#pragma once

#include <string.h>

// Use `alloca` in multiples systems and compilers
#if defined(_MSC_VER)

#include <malloc.h>

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)

#include <stdlib.h>

#else

#include <alloca.h>

#endif

// #include "ds/list/core.h"

/// Allocates an pointer with size `data_size` on the stack
#define LIST_VIEW_GET_STACK_COPY(list_view_ptr, index) \
    memcpy(alloca((list_view_ptr)->data_size), ListView_Get((list_view_ptr), (index)), (list_view_ptr)->data_size)
