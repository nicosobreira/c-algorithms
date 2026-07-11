#include "algo/sort.h"
#include "ds/list.h"

#define SIZE(array) sizeof(array) / sizeof(array[0])

int main(void)
{
    int array[] = {9, 8, 7, 6, 5, 4, 3, 1};
    List list = List_Load(array, SIZE(array), sizeof(array[0]));
    merge_sort(&list, int_increasing);
    List_Print_int(&list);

    double array2[] = {0.9, 0.3, 0.4, 0.1};
    List list2 = List_Load(array2, SIZE(array2), sizeof(array2[0]));
    merge_sort(&list2, double_increasing);
    List_Print_double(&list2);

    return 0;
}
