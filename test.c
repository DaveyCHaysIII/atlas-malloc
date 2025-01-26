#include "malloc.h"

void my_write(const char *str) {
    write(1, str, strlen(str));
}

// Custom function to convert a pointer address to a string (hexadecimal representation)
void print_address(void *ptr) {
    char buf[20];  // Buffer to hold the formatted address
    snprintf(buf, sizeof(buf), "%p", ptr);  // Format the pointer as a hexadecimal string
    my_write(buf);  // Print the address
}

// Testing the _malloc implementation
void test_malloc() {
    // Allocate some blocks using _malloc
    void *block1 = _malloc(4096);  // Allocate 100 bytes
    void *block2 = _malloc(4096);  // Allocate 200 bytes
    void *block3 = _malloc(4096);  // Allocate 300 bytes

    // Check if the blocks were allocated
    if (block1) {
        my_write("Block 1 allocated at address: ");
        print_address(block1);  // Print the address of block1
        my_write("\n");
    } else {
        my_write("Block 1 allocation failed!\n");
    }

    if (block2) {
        my_write("Block 2 allocated at address: ");
        print_address(block2);  // Print the address of block2
        my_write("\n");
    } else {
        my_write("Block 2 allocation failed!\n");
    }

    if (block3) {
        my_write("Block 3 allocated at address: ");
        print_address(block3);  // Print the address of block3
        my_write("\n");
    } else {
        my_write("Block 3 allocation failed!\n");
    }

    _free(block1);
    _free(block2);
    _free(block3);


    // Print out completion message
    my_write("Test completed.\n");
}

// Main function to run the test
int main() {
    test_malloc();
    return 0;
}

