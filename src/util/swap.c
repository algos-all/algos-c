#include "swap.h"

void swap(void *xs, void *ys, size_t size) {
    void *zs = malloc_or_exit(size);

    memcpy(zs, xs, size);
    memcpy(xs, ys, size);
    memcpy(ys, zs, size);
}
