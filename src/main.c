#include "allocator.h"
#include <stdio.h>

int main() {
    init_heap(1024);

    printf("Heap initialized successfully!\n");
   
    void *a = my_malloc(100);
    void *b = my_malloc(200);
    printf("Allocated A=%p, B=%p\n", a, b);

    my_free(a);

    printf("Freed A\n");

    void *c = my_malloc(50);
    printf("Allocated C=%p\n", c);
 
    destroy_heap(); 
    return 0;
}
