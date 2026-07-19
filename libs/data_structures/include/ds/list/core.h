/** @file
 * Generic Dynamic Allocated List library.
 *
 * @note Prefer using the family of function `List_`, avoid accessing the List
 * members.
 *
 * @note There exist defaults loaders for some C types, see the family of
 * functions `List_<action>_<type>`. As an example, when you need to create a
 * new `int` List, use @ref List_New_int.
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "compare/core.h"

// TODO: Add tests to `List_SliceView`

// TODO: Add documentation to `List_SliceView`

/** Generic Dynamic Allocated List.
 */
typedef struct List
{
    const Compare compare;  /**< Compare function (see @ref Compare). */
    const size_t data_size; /**< Size of each element. */
    void *ptr;              /**< Heap allocated pointer to the start. */
    size_t size;            /**< Total of elements. */
    size_t capacity;        /**< Total of elements **allocated**. @note Can be greater then List.size */
} List;

/** Return List.size.
 */
static inline size_t List_Size(const List *self)
{
    return self->size;
}

/** Return `true` if List.size is 0, `false` otherwise.
 */
static inline bool List_IsEmpty(const List *self)
{
    return self->size == 0;
}

/** Create a new heap allocated List.
 * The values on the new list are garbage.
 *
 * @param[in] size Both number of elements and total capacity.
 * @param[in] data_size Size of each element.
 * @param[in] compare Functions for making comparison between elements (see @ref
 * Compare for creating your own).
 *
 * @warning If memory allocation fails, the program is aborted (no `NULL` return).
 */
List List_New(size_t size, size_t data_size, Compare compare);

/** Free an List.
 * The List.ptr is set to `NULL`.
 * Both the List.size and List.capacity are set to 0.
 *
 * @param[in,out] self The List to be changed.
 */
void List_Free(List *self);

/** Create a new list with a capacity.
 * The size of the list is set to 0.
 *
 * @param[in] capacity The desired list capacity.
 * @param[in] data_size The size of each element.
 * @param[in] compare Functions for making comparison between elements
 *                    (see @ref Compare for creating your own).
 */
List List_WithCapacity(size_t capacity, size_t data_size, Compare compare);

/** Creates a new list with the elements of an array.
 * The new list has the same capacity and size of the array.
 *
 * @param[in] array The array of elements.
 * @param[in] size Both the size of the array and the new list.
 * @param[in] data_size The size of each element.
 * @param[in] compare Functions for making comparison between elements
 *                    (see @ref Compare for creating your own).
 */
List List_Load(const void *array, size_t size, size_t data_size, Compare compare);

/** New list slice copy in the range of indexes.
 * Each element from list start_index until end_index is **copied** into the new list.
 * Both the List.data_size and List.compare are copied.
 *
 * @param list[in] The slice is based on the list.
 * @param start_index[in] Inclusive `list` start index.
 * @param end_index[in] Inclusive `list` end index.
 *
 * @note The size of the new list is: `end_index - start_index + 1`.
 *
 * @warning The list slice need to be cleanup using @ref List_Free.
 * @warning If `start_index` is greater than `end_index`, the program is
 *          aborted.
 * @warning If `start_index` is out of bounds, the program is aborted.
 * @warning If `end_index` is out of bounds, the program is aborted.
 */
List List_LoadSlice(const List *list, size_t start_index, size_t end_index);

/** New list slice view in the range of indexes.
 *
 * @warning Don't use functions, because the this is a view:
 *          @ref List_Push, @ref List_Pop, @ref List_Free.
 * @warning If `start_index` is greater than `end_index`, the program is
 *          aborted.
 * @warning If `start_index` is out of bounds, the program is aborted.
 * @warning If `end_index` is out of bounds, the program is aborted.
 */
List List_SliceView(const List *list, size_t start_index, size_t end_index);

/** Get a pointer to an element at index.
 * @warning If the pointer is changed outside, the value in `self` is updated
 *          as well.
 *          In case you want to use a copy instead, prefer @ref List_GetCopy.
 * @warning If `index` is out of bounds, the program is aborted.
 */
void *List_Get(const List *self, size_t index);

/** Get a copy of an element from the list at index.
 * @details The caller takes ownership of the returned memory and is strictly
 *          responsible for releasing it using `free` to prevent memory leaks.
 *
 * @param[in] self  A pointer to the List.
 * @param[in] index The index of the element to copy.
 * @return A void pointer to the newly allocated copy of the element (`NULL`
 *         never is returned).
 *
 * @warning If memory allocation fails, the program is aborted.
 * @warning If `index` is out of bounds, the program is aborted.
 */
void *List_GetCopy(const List *self, size_t index);

/** Set a value to List.
 * @param[in,out] self The List to be changed.
 * @param[in] index The index of the new element `value`.
 * @param[in] value Copies List.data_size from the pointer value into `self`.
 *
 * @warning If `index` is out of bounds, the program is aborted.
 */
void List_Set(List *self, size_t index, void *value);

/** Swap elements in indexes.
 * @param[in,out] self The List to be changed.
 * @param[in] index_a The value in this index will be copied to `index_b`.
 * @param[in] index_b The value in this index will be copied to `index_a`.
 *
 * @warning If `index_a` is out of bounds, the program is aborted.
 * @warning If `index_b` is out of bounds, the program is aborted.
 */
void List_Swap(List *self, size_t index_a, size_t index_b);

/** Push an element to the end of List.
 * If the List capacity is over, it will be resized by a default value.
 *
 * @param[in,out] self The List to be changed
 * @param[in] value Copies List.data_size from the pointer value at the end of List.
 */
void List_Push(List *self, void *value);

/** Pop the last element of List.
 * No elements, only the List.size is decremented by 1.
 *
 * @param self[in,out] self List to be changed.
 *
 * @warning If List.size is 0, the program is aborted.
 */
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
