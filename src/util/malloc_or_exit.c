#include "malloc_or_exit.h"

void *malloc_or_exit(size_t size) {
    void *tmp = malloc(size);

    if (tmp == NULL) {

        if (size == 0) {
            return tmp;
        }

        fprintf(
            stderr, "Failed to malloc %zu bytes: %s",
            size, strerror(errno)
        );

        exit(EXIT_FAILURE);
    }

    return tmp;
}
