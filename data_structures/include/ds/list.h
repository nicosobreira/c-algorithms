#pragma once

#include <stdbool.h>
#include <stddef.h>

/** Dynamic Array with only a data type
 */
typedef struct List
{
    void *ptr;
    size_t size;
    size_t capacity;
    size_t data_size;
} List;

List List_New(size_t size, size_t data_size);

void List_Free(List *self);

List List_WithCapacity(size_t capacity, size_t data_size);

static inline size_t List_Size(List *self)
{
    return self->size;
}

static inline bool List_IsEmpty(List *self)
{
    return self->size == 0;
}

List List_Load(void *array, size_t size, size_t data_size);

/// Creates an copy of list from indexes start to end (inclusive)
List List_NewSlice(List *list, size_t start_index, size_t end_index);

void *List_Get(List *self, size_t index);

/**
 * @brief Retrieves a copy of an element from the list at the specified index.
 *
 * This function allocates a new memory block on the heap using \c malloc,
 * copies the contents of the element found at the given \p index into it,
 * and returns the pointer to this new copy.
 *
 * @note The caller takes ownership of the returned memory and is strictly
 * responsible for releasing it using \c free() to prevent memory leaks.
 *
 * @note In case the \c malloc fail, returning \c NULL, the function will abort the program.
 *
 * @param[in] self  A pointer to the List instance.
 * @param[in] index The zero-based index of the element to copy.
 * * @return A void pointer to the newly allocated copy of the element (\c NULL
 * never is returned).
 *
 * @pre The \p index must be within the bounds of the list (index < self->size).
 * This boundary condition is enforced internally via an assertion.
 */
void *List_GetCopy(List *self, size_t index);

void List_Set(List *self, size_t index, void *value);

void List_Swap(List *self, size_t index_a, size_t index_b);

void List_Push(List *self, void *value);

void List_Pop(List *self);

// ------------------------------------------------------------

void List_Print_int(List *self);

void List_Print_float(List *self);

void List_Print_double(List *self);
