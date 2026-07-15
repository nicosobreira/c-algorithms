#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "compare/core.h"

/** Dynamic Array
 */
typedef struct List
{
    const Compare compare;
    const size_t data_size;
    void *ptr;
    size_t size;
    size_t capacity;
} List;

/** Create a new heap allocated List.
 * @warning If \c malloc fails, the program is aborted (no \c NULL return).
 *
 * @param[in] size Both number of elements and total capacity.
 * @param[in] data_size The size of each element.
 * @param[in] compare Functions for making comparison between elements.
 */
List List_New(size_t size, size_t data_size, Compare compare);

void List_Free(List *self);

List List_WithCapacity(size_t capacity, size_t data_size, Compare compare);

List List_Load(const void *array, size_t size, size_t data_size, Compare compare);

static inline size_t List_Size(const List *self)
{
    return self->size;
}

static inline bool List_IsEmpty(const List *self)
{
    return self->size == 0;
}

/// Creates an copy of list from indexes start to end (inclusive)
List List_NewSlice(const List *list, size_t start_index, size_t end_index);

void *List_Get(const List *self, size_t index);

/** Retrieves a copy of an element from the list at the specified index.
 * @details The caller takes ownership of the returned memory and is strictly
 * responsible for releasing it using \c free() to prevent memory leaks.
 * @param self  A pointer to the List instance.
 * @param index The zero based index of the element to copy.
 * @return A void pointer to the newly allocated copy of the element (\c NULL
 * never is returned).
 *
 * @note In case the \c malloc fail, the function will abort the program.
 *
 * @warning The \p index must be within the bounds of the list (index < self->size).
 */
void *List_GetCopy(const List *self, size_t index);

void List_Set(List *self, size_t index, void *value);

void List_Swap(List *self, size_t index_a, size_t index_b);

void List_Push(List *self, void *value);

void List_Pop(List *self);

// ------------------------------------------------------------

static inline bool List_Compare_Equals(const List *self, const void *a, const void *b)
{
    return Compare_Equals(&self->compare, a, b);
}

static inline bool List_Compare_Less(const List *self, const void *a, const void *b)
{
    return Compare_Less(&self->compare, a, b);
}

static inline bool List_Compare_Greater(const List *self, const void *a, const void *b)
{
    return Compare_Greater(&self->compare, a, b);
}

// ------------------------------------------------------------

List List_New_int(size_t size);

List List_WithCapacity_int(size_t capacity);

List List_Load_int(const int *array, size_t size);

List List_New_double(size_t size);

List List_WithCapacity_double(size_t capacity);

List List_Load_double(const double *array, size_t size);

// ------------------------------------------------------------

void List_Print_int(const List *self);

void List_Print_double(const List *self);
