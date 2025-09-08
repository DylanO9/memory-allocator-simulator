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

void *my_malloc(size_t size) {
    size = ALIGN4(size); // Align to 4 bytes
    
    block_header* curr = free_list;

    while (curr) {
        if (curr->free &&  size <= curr->size) {
            if (curr->size >= size + sizeof(block_header) + 4) {
                block_header* new_block = (block_header *)((char *)curr + sizeof(block_header) + size);
                new_block->size = curr->size - size - sizeof(block_header);
                new_block->free = 1;
                new_block->next = curr->next;
                curr->next = new_block; 
                curr->size = size;
            }
            curr->free = 0;
            return (char *) curr + sizeof(block_header);
        } 
        curr = curr->next;
    }    
    return NULL;
}

void my_free(void* ptr) {
    if (!ptr) return;
    block_header* block = (block_header*)((char *)ptr - sizeof(block_header));
    block->free = 1;
    
    if (block->next && block->next->free) {
        block->size += sizeof(block_header) + block->next->size;
        block->next = block->next->next; 
    }
}
