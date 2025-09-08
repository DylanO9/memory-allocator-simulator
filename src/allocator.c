#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"

#define ALIGN4(x) (((x) + 3) & ~3) // align to 4 bytes

static void* heap = NULL;
static block_header* free_list = NULL;

void init_heap(size_t size) {
    heap = malloc(size);
    
    if (heap == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    free_list = (block_header*)heap;
    free_list->size = size - sizeof(block_header);
    free_list-> free = 1;
    free_list->next = NULL;

    printf("Heap initialized: %zu bytes usable memory\n", free_list->size);
}

void destroy_heap() {
    free(heap);
    heap = NULL;
    free_list = NULL;
    printf("Heap was destroyed successfully!\n");
}
