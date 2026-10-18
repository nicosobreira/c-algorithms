/** @file
 * Generic List View.
 *
 * Use this module if you code **doesn't** do any memory related operations on a
 * List, like pushing (@ref List_Push) or popping (@ref List_Pop) an element, as
 * well as allocating or freeing the List.
 *
 * @note Prefer using the family of function `ListView_`, avoid accessing the List members.
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "compare/core.h"

#include "operations/core.h"

typedef struct ListView
{
    const Operations operations; /**< @ref Operations. */
    const Compare compare;       /**< Compare function (see @ref Compare). */
    const size_t data_size;      /**< Size of each element. */
    void *ptr;                   /**< Pointer to the start of the view. */
    size_t size;                 /**< Total of elements. */
} ListView;

ListView ListView_New(void *ptr, size_t data_size, size_t size, Compare compare, Operations operations);

static inline size_t ListView_Size(const ListView *self)
{
    return self->size;
}

static inline bool ListView_IsEmpty(const ListView *self)
{
    return self->size == 0;
}

static inline size_t ListView_DataSize(const ListView *self)
{
    return self->data_size;
}

/** Get a pointer to an element at index.
 * @warning If the pointer is changed outside, the value in `self` is updated
 *          as well.
 *          In case you want to use a copy instead, use @ref ListView_GetCopy.
 * @warning If `index` is out of bounds, the program is aborted.
 */
void *ListView_Get(const ListView *self, size_t index);

/** Get a copy of an element from the list at index.
 * @details The caller takes ownership of the returned memory and is strictly
 *          responsible for releasing it using `free` to prevent memory leaks.
 *
 * @param[in] self  A pointer to the ListView.
 * @param[in] index The index of the element to copy.
 * @return A void pointer to the newly allocated copy of the element (`NULL`
 *         never is returned).
 *
 * @warning If memory allocation fails, the program is aborted.
 * @warning If `index` is out of bounds, the program is aborted.
 */
void *ListView_GetCopy(const ListView *self, size_t index);

/** Set a value to ListView.
 * @param[in,out] self The ListView to be changed.
 * @param[in] index The index of the new element `value`.
 * @param[in] value Copies ListView.data_size from the pointer value into `self`.
 *
 * @warning If `index` is out of bounds, the program is aborted.
 */
void ListView_Set(ListView *self, size_t index, void *value);

/** Swap elements in indexes.
 * @param[in,out] self The ListView to be changed.
 * @param[in] index_a The value in this index will be copied to `index_b`.
 * @param[in] index_b The value in this index will be copied to `index_a`.
 *
 * @warning If `index_a` is out of bounds, the program is aborted.
 * @warning If `index_b` is out of bounds, the program is aborted.
 */
void ListView_Swap(ListView *self, size_t index_a, size_t index_b);

void ListView_Pop(ListView *self);
