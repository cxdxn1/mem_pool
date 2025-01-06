#ifndef heap_alloc_h
#define heap_alloc_h

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* ptr;
    size_t size;
    bool isFree;
} mem_block_t;

#endif /* heap_alloc_h */