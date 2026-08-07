#include "algo/sort.h"

#include "ds/list/core.h"

/**
# Invariante do Loop - Bubble Sort

Pseudocódigo do Bubble Sort:

> Os indices do array A vão de 1 até n.

```
1  for i = 1 to A.length - 1
2    for j = A.length downto i + 1
3      if A[j] < A[j - 1]
4        exchange A[j] with A[j - 1]
```

## Invariante do Loop 2-4

No começo de cada iteração do for loop 2-4, A\[j\] é o menor elemento do subarray A\[j..n\], uma permutação do subarray
original.

> Ao final, A\[j - 1\] deve ser o menor elemento de A\[j - 1..n\].

### Inicialização

No início, j = n. Dessa forma, A\[j\] é o menor elemento do subarray A\[j..n\], este que possui apenas um elemento:
A\[n\].

### Manutenção

Caso A\[j\] seja menor que A\[j - 1\], assumimos que A\[j\] = min(A\[j..n\]). Trocamos os elementos de lugar, tornando
A\[j - 1..n\] uma permutação do subarray original e A\[j - 1\] o menor elemento do subarray. Ao decrementarmos j por 1,
mantemos a invariante do loop. Contudo, se A\[j\] for maior ou igual a A\[j - 1\], assumimos que A\[j - 1\] =
min(A\[j..n\]). A\[j - 1\] é o menor elemento do subarray A\[j - 1..n\]. Ao decrementarmos j por 1, mantemos a
invariante do loop.

### Finalização

Ao final, j = i. **Portanto A\[i\] é o menor elemento do subarray A\[i..n\].**

## Invariante do Loop 1-4

No começo de cada iteração do for loop 1-4, o subarray A\[1..i - 1\] possui os i - 1 menores elementos do array
original em ordem crescente.

### Inicialização

No início, i = 1. Dessa forma, o subarray A\[1..i - 1\] não possui elementos, e portanto é uma permutação ordenada
vacuosamente.

### Manutenção

Ao final do loop, pela Invariante do Loop 2-4, A\[i\] é o menor elemento do subarray A\[i..n\]. Com isso A\[1..i\]
possui os i menores elementos do array original em ordem crescente.

### Finalização

Ao final, i = n. Dessa forma, o array A\[1..n - 1\] possui os n - 1 menores elementos do array original em ordem
crescente. **Pela Manutenção, A\[n\] é maior ou igual a A\[n - 1\]; com isso o array A está ordenado.**
*/
void bubble_sort(List *list)
{
    const size_t last_index = List_Size(list) - 1;

    for (size_t i = 0; i < last_index; ++i)
    {
        for (size_t j = last_index; j >= i + 1; --j) // downto
        {
            void *current = List_Get(list, j);
            void *previous = List_Get(list, j - 1);

            if (List_Compare_Less(list, current, previous))
            {
                List_Swap(list, j, j - 1);
            }
        }
    }
}
