/** @file
 * Generic Dynamic Allocated List library.
 *
 * @note Prefer using the family of function `List_`, avoid accessing the List
 * members.
 *
 * @note There exist defaults loaders for some C types, see the family of
 * functions `List_<action>_<type>`. As an example, when you need to create a
 * *new* `int` List, use @ref List_New_int.
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "compare/core.h"

#include "view.h"

/** Generic Dynamic Allocated List.
 * The implemantation is using a **compositive** approach: ListView plus the
 * capacity.
 */
typedef struct List
{
    ListView view;
    size_t capacity; /**< Total of elements **allocated**. @note Can be greater then ListView.size */
} List;

static inline ListView *List_View_mut(List *self)
{
    return &self->view;
}

static inline const ListView *List_View_const(const List *self)
{
    return &self->view;
}

/** Return List.view
 * Use this macro when you need to pass a List.view as a parameter to another
 * function that excepts a ListView.
 *
 * As an example, for the function `void my_sort(ListView self)` you would pass
 * `sort(List_View(my_list))`.
 */
#define LIST_VIEW(self) _Generic((self), List *: List_View_mut, const List *: List_View_const)(self)

/** Return ListView.size.
 */
static inline size_t List_Size(const List *self)
{
    return self->view.size;
}

static inline void *List_Ptr(const List *self)
{
    return self->view.ptr;
}

/** Return `true` if ListView.size is 0, `false` otherwise.
 */
static inline bool List_IsEmpty(const List *self)
{
    return ListView_IsEmpty(&self->view);
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

// TODO: See if it makes sense to move List_Load to ListView.

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

// FIX: A onde eu coloco `ListView_LoadSlice`?

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
List ListView_LoadSlice(const ListView *view, size_t start_index, size_t end_index);

// FIX: Erro de List_View ignorando o const

static inline List List_LoadSlice(const List *list, size_t start_index, size_t end_index)
{
    return ListView_LoadSlice(LIST_VIEW(list), start_index, end_index);
}

/** New list slice view in the range of indexes.
 *
 * @warning Don't use functions, because the this is a view:
 *          @ref List_Push, @ref List_Pop, @ref List_Free.
 * @warning If `start_index` is greater than `end_index`, the program is
 *          aborted.
 * @warning If `start_index` is out of bounds, the program is aborted.
 * @warning If `end_index` is out of bounds, the program is aborted.
 */
ListView ListView_NewSlice(const ListView *view, size_t start_index, size_t end_index);

static inline ListView List_NewSlice(const List *list, size_t start_index, size_t end_index)
{
    return ListView_NewSlice(LIST_VIEW(list), start_index, end_index);
}

static inline void *List_Get(const List *self, size_t index)
{
    return ListView_Get(&self->view, index);
}

static inline void *List_GetCopy(const List *self, size_t index)
{
    return ListView_GetCopy(&self->view, index);
}

static inline void List_Set(List *self, size_t index, void *value)
{
    ListView_Set(&self->view, index, value);
}

static inline void List_Swap(List *self, size_t index_a, size_t index_b)
{
    ListView_Swap(&self->view, index_a, index_b);
}

/** Push an element to the end of List.
 * If the List capacity is over, it will be resized by a default value.
 *
 * @param[in,out] self The List to be changed
 * @param[in] value Copies List.data_size from the pointer value at the end of List.
 */
void List_Push(List *self, void *value);

// TODO: See if it makes sense to move List_Pop logic to ListView.

/** Pop the last element of List.
 * No elements, only the List.size is decremented by 1.
 *
 * @param self[in,out] self List to be changed.
 *
 * @warning If List.size is 0, the program is aborted.
 */
static inline void List_Pop(List *self)
{
    ListView_Pop(&self->view);
}

// ------------------------------------------------------------

static inline bool List_Compare_Equals(const List *self, const void *a, const void *b)
{
    return ListView_Compare_Equals(&self->view, a, b);
}

static inline bool List_Compare_Less(const List *self, const void *a, const void *b)
{
    return ListView_Compare_Less(&self->view, a, b);
}

static inline bool List_Compare_Greater(const List *self, const void *a, const void *b)
{
    return ListView_Compare_Greater(&self->view, a, b);
}
