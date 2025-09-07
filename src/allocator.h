#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

typedef struct block_header {
    size_t size;
    bool free;
    struct block_header* next;
} block_header;

void init_heap(size_t size);

#endif // ALLOCATOR_H
