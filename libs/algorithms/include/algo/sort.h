#pragma once

#include <stdbool.h>

#include "ds/list/view.h"

// TODO: Será que faz sentido passar essas `List` por valor (ao invés de usar
// ponteiros)? A minha tese é que isso melhoria a localidade na memória.

void merge_sort(ListView *list);

void insertion_sort(ListView *list);

void bubble_sort(ListView *list);
