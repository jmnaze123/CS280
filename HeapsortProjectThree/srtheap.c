#include <stdlib.h>
#include <string.h>
#include "srt.h"

void heapify(char *array, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *));

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {
    
    char *array;
    size_t i;
    array = malloc((size + 1) * nelem);
    memcpy(array + size, base, nelem * size);

    for (i = nelem / 2; i >= 1; i--) {

        heapify(array, nelem, size, i, compar);
    }

    for (i = nelem; i > 1; i--) {

        swap(array + size, array + i * size, size);
        heapify(array, i - 1, size, 1, compar);
    }

    memcpy(base, array + size, nelem * size);
    free(array);
}


void heapify(char *array, size_t nelem, size_t size, size_t parent, int (*compar)(const void *, const void *)) {
    
    size_t child;
    while ((child = 2 * parent) <= nelem) {

        if (child + 1 <= nelem && compar(array + child * size, array + (child + 1) * size) < 0) {

            child = child + 1;
        }
            if (compar(array + parent * size, array + child * size) < 0) {

                swap(array + parent * size, array + child * size, size);
                parent = child;
            } else {

                break;
            }
    }
}