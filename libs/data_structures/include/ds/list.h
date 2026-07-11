#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "compare/core.h"

// TODO: Eu tive uma idea, será que vale a pena criar vários ponteiros de
// funções constantes para as funções `compare`? Seriam 3 funções: equal, less e
// less equal. O not_equal é a negação do equal, as versões greater são a negação das duas últimas.
// Na ora de inicializar, pode colocar `NULL`, vai ser na ora do uso que essas
// variáveis vão ser checadas.
// Essas funções ficariam em um struct chamado `compare` as operações seriam
// abstraidas.

/** Dynamic Array with only a data type
 */
typedef struct List
{
    const Compare compare;
    void *ptr;
    size_t size;
    size_t capacity;
    const size_t data_size; // TODO: Ver se faz sentido fazer `const` data_size
} List;

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
 *
 * @note The caller takes ownership of the returned memory and is strictly
 * responsible for releasing it using \c free() to prevent memory leaks.
 *
 * @note In case the \c malloc fail, the function will abort the program.
 *
 * @param[in] self  A pointer to the List instance.
 * @param[in] index The zero-based index of the element to copy.
 * * @return A void pointer to the newly allocated copy of the element (\c NULL
 * never is returned).
 *
 * @pre The \p index must be within the bounds of the list (index < self->size).
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

void List_Print_int(const List *self);

void List_Print_double(const List *self);

// ------------------------------------------------------------

List List_New_int(size_t size);

List List_WithCapacity_int(size_t capacity);

List List_Load_int(const int *array, size_t size);

List List_New_double(size_t size);

List List_WithCapacity_double(size_t capacity);

List List_Load_double(const double *array, size_t size);
