#include "ds/heap/core.h"

#include "ds/heap/compare.h"

static bool is_max(const Heap *heap, size_t node)
{
    if (Heap_IsLeaf(heap, node))
    {
        return true;
    }

    size_t left = Heap_LeftIndex(node);
    size_t right = Heap_RightIndex(node);

    bool left_exists = Heap_IsLeaf(heap, left);
    bool right_exists = Heap_IsLeaf(heap, right);

    if (!left_exists)
    {
        if (right_exists)
        {
            if (Heap_Compare_GreaterEqualAt(heap, node, right))
            {
                return is_max(heap, right);
            }

            return false;
        }

        return true;
    }
    if (!right_exists)
    {
        if (left_exists)
        {
            if (Heap_Compare_GreaterEqualAt(heap, node, left))
            {
                return is_max(heap, left);
            }
            return false;
        }

        return true;
    }

    if (Heap_Compare_GreaterEqualAt(heap, node, left) && Heap_Compare_GreaterEqualAt(heap, node, right))
    {
        bool check_left = is_max(heap, left);
        bool check_right = is_max(heap, right);

        return check_left && check_right;
    }

    return false;
}

bool Heap_IsMax(const Heap *heap)
{
    return is_max(heap, 0);
}

bool Heap_IsMin(const Heap *heap)
{
    return true;
}
