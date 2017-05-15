#pragma once

#include "comparators.h"
#include "util/malloc_or_exit.h"

void mergesort0(
    void *, size_t, size_t, int (*) (const void *, const void *)
);
