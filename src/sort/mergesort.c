#include "mergesort.h"

void mergesort0(
    void *xs, size_t n, size_t s,
    int (*cmp) (const void *, const void *)
) {
    if (n == 0 || n == 1) return;

    const size_t nlft = n / 2;
    const size_t nrgt = n - nlft;

    void *ys = (char *)xs + nlft * s;

    mergesort0(xs, nlft, s, cmp);
    mergesort0(ys, nrgt, s, cmp);

    void *const as = malloc_or_exit(n * s);
    void *const bs = (char *)as + nlft * s;
    void *const cs = (char *)as + n * s;

    memcpy(as, xs, n * s);

    void const *i = as;
    void const *j = bs;
    while (i != bs && j != cs) {
        if (cmp(i, j) <= 0) {
            memcpy(xs, i, s);
            i = (char *)i + s;
        } else {
            memcpy(xs, j, s);
            j = (char *)j + s;
        }

        xs = (char *)xs + s;
    }

    for (; i != bs; i = (char *)i + s, xs = (char *)xs + s) {
        memcpy(xs, i, s);
    }

    for (; j != cs; j = (char *)j + s, xs = (char *)xs + s) {
        memcpy(xs, j, s);
    }

    free(as);
}

#include <stdio.h>
int main() {
    int xs[] = {1, 2, -3, 4, -5};
    int ys[] = {5, 4, 3, 2, 1};
    int zs[] = {3, 1, 2, 4, 5};
    int as[] = {1, 1, 1};
    int bs[] = {3, 2, 2};

    int len = 5;

    mergesort0(xs, len, sizeof(int), compare_int);

    for (int i = 0; i < len; ++i) {
        printf("%d ", *(xs + i));
    } printf("\n");
}
