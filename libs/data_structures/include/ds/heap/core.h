#pragma once

#include "ds/list/core.h"

typedef struct Heap
{
    List list;
    size_t size;
} Heap;

static inline size_t Heap_Size(const Heap *self)
{
    return self->size;
}

static inline bool Heap_IsLeaf(const Heap *self, size_t node)
{
    return node >= self->size;
}

static inline size_t Heap_ParentIndex(size_t node)
{
    return (node - 1) / 2;
}

static inline size_t Heap_LeftIndex(size_t node)
{
    return 1 + (2 * node);
}

static inline size_t Heap_RightIndex(size_t node)
{
    return 2 * (node + 1);
}

static inline Heap Heap_WithCapacity(size_t capacity, size_t data_size, Compare compare, Operations operations)
{
    return (Heap){
        .list = List_WithCapacity(capacity, data_size, compare, operations),
        .size = 0,
    };
}

static inline Heap Heap_Load(const void *array, size_t size, size_t data_size, Compare compare, Operations operations)
{
    return (Heap){
        .list = List_Load(array, size, data_size, compare, operations),
        .size = size,
    };
}

static inline void *Heap_Get(const Heap *self, size_t node)
{
    return List_Get(&self->list, node);
}

static inline void Heap_Swap(Heap *self, size_t a, size_t b)
{
    List_Swap(&self->list, a, b);
}

bool Heap_IsMax(const Heap *heap);

bool Heap_IsMin(const Heap *heap);
