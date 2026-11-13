#include "ds/heap/heapify.h"

#include "ds/heap/compare.h"
#include "ds/heap/core.h"

void Heap_MaxHeapify(Heap *self, size_t node)
{
    size_t left = Heap_LeftIndex(node);
    size_t right = Heap_RightIndex(node);

    size_t largest = node;
    if (!Heap_IsLeaf(self, left) && Heap_Compare_GreaterAt(self, left, largest))
    {
        largest = left;
    }
    if (!Heap_IsLeaf(self, right) && Heap_Compare_GreaterAt(self, right, largest))
    {
        largest = right;
    }

    if (largest != node)
    {
        Heap_Swap(self, largest, node);
        Heap_MaxHeapify(self, largest);
    }
}
