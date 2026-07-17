#pragma once

#include "core.h"

List List_New_int(size_t size);

List List_WithCapacity_int(size_t capacity);

List List_Load_int(const int *array, size_t size);

// ------------------------------------------------------------

List List_New_double(size_t size);

List List_WithCapacity_double(size_t capacity);

List List_Load_double(const double *array, size_t size);
