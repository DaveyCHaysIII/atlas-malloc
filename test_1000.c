#include "malloc.h"


void test_malloc() {
    void *ptr;
    size_t i;

    for (i = 0; i < 1000; i++) {
        ptr = _malloc(1); // Request 1 byte of memory
        if (ptr == NULL) {
		write(1, "failed", 6);
        } else {
		write(1, "test # ", 7);
		_write_size(i);
		write(1, " success\n", 9);
        }
    }

    printf("Test completed.\n");
}


void _write_size(size_t size)
{
	static char buffer[20];
	snprintf(buffer, sizeof(buffer), "%lu", size);
	write(1, buffer, strlen(buffer));
}

int main() {
    test_malloc();
    return 0;
}

