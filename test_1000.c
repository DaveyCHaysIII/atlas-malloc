#include "malloc.h"


void test_malloc() {
    void *ptr;
    size_t i;

    for (i = 0; i < 1000; i++) {
        ptr = _malloc(1); // Request 1 byte of memory
        if (ptr == NULL) {
            printf("Allocation %zu failed\n", i + 1);
        } else {
            printf("Block %zu allocated at address: %p\n", i + 1, ptr);
        }
    }

    printf("Test completed.\n");
}

int main() {
    test_malloc();
    return 0;
}

