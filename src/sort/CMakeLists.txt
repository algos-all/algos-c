add_library(comparators comparators.c comparators.h)

add_library(mergesort mergesort.c mergesort.h)

target_link_libraries(mergesort comparators malloc_or_exit)
