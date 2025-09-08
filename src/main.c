#include "allocator.h"
#include <stdio.h>

int main() {
    init_heap(100);

    printf("Heap initialized successfully!\n");
    destroy_heap(); 
    return 0;
}
