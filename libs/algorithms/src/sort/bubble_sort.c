#include "algo/sort.h"

#include "ds/list/view.h"

/**
# Bubble Sort

## Invariante do Loop

Pseudocódigo do Bubble Sort:

> Os indices do array A vão de 1 até n.

```
1  for i = 1 to A.length - 1
2    for j = A.length downto i + 1
3      if A[j] < A[j - 1]
4        exchange A[j] with A[j - 1]
```

### Invariante do Loop 2-4

No começo de cada iteração do for loop 2-4, A\[j\] é o menor elemento do subarray A\[j..n\], uma permutação do subarray
original.

> Ao final, A\[j - 1\] deve ser o menor elemento de A\[j - 1..n\].

#### Inicialização

No início, j = n. Dessa forma, A\[j\] é o menor elemento do subarray A\[j..n\], este que possui apenas um elemento:
A\[n\].

#### Manutenção

Caso A\[j\] seja menor que A\[j - 1\], assumimos que A\[j\] = min(A\[j..n\]). Trocamos os elementos de lugar, tornando
A\[j - 1..n\] uma permutação do subarray original e A\[j - 1\] o menor elemento do subarray. Ao decrementarmos j por 1,
mantemos a invariante do loop. Contudo, se A\[j\] for maior ou igual a A\[j - 1\], assumimos que A\[j - 1\] =
min(A\[j..n\]). A\[j - 1\] é o menor elemento do subarray A\[j - 1..n\]. Ao decrementarmos j por 1, mantemos a
invariante do loop.

#### Finalização

Ao final, j = i. **Portanto A\[i\] é o menor elemento do subarray A\[i..n\].**

### Invariante do Loop 1-4

No começo de cada iteração do for loop 1-4, o subarray A\[1..i - 1\] possui os i - 1 menores elementos do array
original em ordem crescente.

#### Inicialização

No início, i = 1. Dessa forma, o subarray A\[1..i - 1\] não possui elementos, e portanto é uma permutação ordenada
vacuosamente.

#### Manutenção

Ao final do loop, pela Invariante do Loop 2-4, A\[i\] é o menor elemento do subarray A\[i..n\]. Com isso A\[1..i\]
possui os i menores elementos do array original em ordem crescente.

#### Finalização

Ao final, i = n. Dessa forma, o array A\[1..n - 1\] possui os n - 1 menores elementos do array original em ordem
crescente. **Pela Manutenção, A\[n\] é maior ou igual a A\[n - 1\]; com isso o array A está ordenado.**

## Análise do Tempo

Para todos os casos (melhor, médio e pior) o Bubble Sort tem um crescimento de \f$\Theta(n^2)\f$.

Seja \f$c\f$ o tempo gasto em uma iteração do loop 2-4. Sabemos que o loop 1-4 vai de \f$1\f$ até \f$n - 1\f$. Já o loop
2-4, vai de \f$i + 1\f$ até \f$n\f$. Por conta de um loop estar dentro do outro, podemos representar isso
matematicamente por um **somatório** duplo. Resolvemos ele a seguir:

\f[
\begin{equation*}
\begin{split}
    \sum_{i = 1}^{n - 1}\sum_{j = i + 1}^{n} c &= c \sum_{i = 1}^{n - 1}\sum_{j = i + 1}^{n} \\
    &= c(n - 2 + n - 3 + \dots + n - (n - 2) + n - (n - 1)) \\
    &= c(n - 2 + n - 3 + \dots + 2 + 1) \\
\end{split}
\end{equation*}
\f]

Ao final, chegamos a essa Progressão Aritmética: \f$PA(1, 2, 3 + \dots + n - 3 + n - 2)\f$. Agora, falta somar esses
elementos:

\f[
\begin{equation*}
\begin{split}
    S_{n - 2} &= \frac{(n - 2)(1 + n - 2)}{2} \\
    &= \frac{n + n^2 - 2n -2 -2n + 4}{2} \\
    &= \frac{n^2 -3n + 2}{2}
\end{split}
\end{equation*}
\f]

Portanto, ao aplicarmos o notação assintótica nessa equação, chegamos em \f$\Theta(n^2)\f$.
*/
void bubble_sort(ListView *list)
{
    const size_t last_index = ListView_Size(list) - 1;

    for (size_t i = 0; i < last_index; ++i)
    {
        for (size_t j = last_index; j >= i + 1; --j) // down to
        {
            void *current = ListView_Get(list, j);
            void *previous = ListView_Get(list, j - 1);

            if (ListView_Compare_Less(list, current, previous))
            {
                ListView_Swap(list, j, j - 1);
            }
        }
    }
}
