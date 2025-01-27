#include "malloc.h"

void write_address(void *ptr);
void write_size(size_t size);

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
    void *block1 = _malloc(8192);  // Allocate 100 bytes
    void *block2 = _malloc(8192);  // Allocate 200 bytes
    void *block3 = _malloc(8192);  // Allocate 300 bytes

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
    void *block4 = _malloc(200);
    void *block5 = _malloc(300);
    void *block6 = _malloc(100);

    if (block4) {
        my_write("Block 4 allocated at address: ");
        print_address(block4);  // Print the address of block2
        my_write("\n");
    } else {
        my_write("Block 4 allocation failed!\n");
    }

    if (block5) {
        my_write("Block 5 allocated at address: ");
        print_address(block5);  // Print the address of block2
        my_write("\n");
    } else {
        my_write("Block 5 allocation failed!\n");
    }


    if (block6) {
        my_write("Block 6 allocated at address: ");
        print_address(block6);  // Print the address of block2
        my_write("\n");
    } else {
        my_write("Block 6 allocation failed!\n");
    }
    _free(block2);
    _free(block3);

    _free(block4);
    _free(block5);
    _free(block6);


    // Print out completion message
    my_write("Test completed.\n");
}

// Main function to run the test
int main() {
    test_malloc();
    return 0;
}


void write_address(void *ptr)
{
	static char buffer[20];
	snprintf(buffer, sizeof(buffer), "0x%p\n", ptr);
	write(1, buffer, strlen(buffer));
}


void write_size(size_t size)
{
	static char buffer[20];
	snprintf(buffer, sizeof(buffer), "%lu\n", size);
	write(1, buffer, strlen(buffer));
}
