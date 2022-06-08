/*
 *
 *  after splitting this file into the five source files:
 *
 *	srt.h, main.c, srtbubb.c, srtinsr.c, srtmerg.c
 *
 *  compile using the command:
 *
 *	gcc -std=c99 -DRAND -DPRNT -DTYPE=(float | double) -D(BUBB | HEAP | INSR | MERG) *.c
 *
 */

/*
 *
 *  srt.h file
 *
 */

#ifndef SRT_H
#define SRT_H

#include <string.h>

#define MAX_BUF 256

#define swap(qx,qy,sz)                                              \
do {                                                                \
    char buf[MAX_BUF];                                              \
    char *q1 = qx;                                                  \
    char *q2 = qy;                                                  \
    for (size_t m, ms = sz; ms > 0; ms -= m, q1 += m, q2 += m) {    \
        m = ms < sizeof(buf) ? ms : sizeof(buf);                    \
        memcpy(buf, q1, m);                                         \
        memcpy(q1, q2, m);                                          \
        memcpy(q2, buf, m);                                         \
    }                                                               \
} while (0)

void srtbubb(void *, size_t, size_t, int (*)(const void *, const void *));
void srtheap(void *, size_t, size_t, int (*)(const void *, const void *));
void srtinsr(void *, size_t, size_t, int (*)(const void *, const void *));
void srtmerg(void *, size_t, size_t, int (*)(const void *, const void *));

#endif /* SRT_H */

/*
 *
 *  main.c file
 *
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "srt.h"

static int compare(const void *, const void *);

int main(int argc, char *argv[]) {

    int nelem = argc == 2 ? atoi(argv[1]) : SHRT_MAX;

    TYPE *a = calloc(nelem, sizeof(TYPE));

#ifdef RAND
    for (int i = 0; i < nelem; ++i) {

        a[i] = (TYPE)rand() / RAND_MAX;
    }
#else
    for (int i = 0; i < nelem; ++i) {

        a[i] = i;
    }
#endif

#if defined BUBB
    srtbubb(a, nelem, sizeof(TYPE), compare);
#elif defined HEAP
    srtheap(a, nelem, sizeof(TYPE), compare);
#elif defined INSR
    srtinsr(a, nelem, sizeof(TYPE), compare);
#elif defined MERG
    srtmerg(a, nelem, sizeof(TYPE), compare);
#else
    qsort(a, nelem, sizeof(TYPE), compare);
#endif

#ifdef PRNT
    for (int i = 0; i < nelem; ++i) {

        printf("%f\n", a[i]);
    }
#else
    for (int i = 0; i < nelem - 1; ++i) {

        if (a[i] > a[i + 1]) {

            printf("fail\n");
            goto end;
        }
    }

    printf("pass\n");
#endif

end:

    free(a);

    return 0;
}

static int compare(const void *p1, const void *p2) {

    if (*(TYPE *)p1 < *(TYPE *)p2) {

        return -5;
    }
    else if (*(TYPE *)p1 > *(TYPE *)p2) {

        return +5;
    }

    return 0;
}

/*
 *
 *  srtbubb.c file
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include "srt.h"

void srtbubb(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    for (size_t i = nelem - 1; i > 0; --i) {

        bool sorted = true;

        for (size_t j = 0; j < i; ++j) {

            char *qj = (char *)base + size * j;
            char *qn = qj + size;

            if (compar(qj, qn) > 0) {

	            swap(qj, qn, size);
	            sorted = false;
            }
        }

        if (sorted) {
            break;
        }
    }

    return;
}

/*
 *
 *  srtinsr.c file
 *
 */

#include <stdlib.h>
#include <string.h>
#include "srt.h"

void srtinsr(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    char buf[size], *qb = base;

    for (size_t i = 1; i < nelem; ++i) {

        memcpy(buf, qb + size * i, size);

        size_t j = i;

        while (j > 0 && compar(buf, qb + size * (j - 1)) < 0) {

            memcpy(qb + size * j, qb + size * (j - 1), size);
            --j;
        }

        memcpy(qb + size * j, buf, size);
    }

    return;
}

/*
 *
 *  srtmerg.c file
 *
 */

#include <stdlib.h>
#include <string.h>
#include "srt.h"

void srtmerg(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    char *qb = base, *ql, *qr, *qt;
    size_t i, j, l, r;

    if (nelem <= 1) {
        return;
    }
    else if (nelem == 2) {
        if (compar(qb, qb + size) > 0) {
            swap(qb, qb + size, size);
        }
        return;
    }

    l = nelem / 2;
    r = nelem - l;

    ql = qt = malloc(size * l);
    memcpy(ql, qb, size * l);

    qr = qb + size * l;

    srtmerg(ql, l, size, compar);
    srtmerg(qr, r, size, compar);

    i = 0; j = l;

    while(i < l && j < nelem) {
        if (compar(ql, qr) <= 0) {
            memcpy(qb, ql, size);
            qb += size;
            ql += size;
            ++i;
        }
        else {
            memcpy(qb, qr, size);
            qb += size;
            qr += size;
            ++j;
        }
    }

    if (i < l) {
        memcpy(qb, ql, size * (l - i));
    }

    free(qt);

    return;
}