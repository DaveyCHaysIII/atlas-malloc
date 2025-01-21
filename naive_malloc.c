#include "malloc.h"

/**
 * naive_malloc - the naive implementation of malloc
 * @size: size of allocation
 *
 * Return: void * to allocated memory in heap
 */

void *naive_malloc(size_t size)
{
	static void *heap_start;
	static void *heap_end;
	static size_t chunks;
	nmheader_t *chunk_header, *new_header;
	void *chunk;

	if (!heap_start)
	{
		heap_start = sbrk(0);
		heap_end = sbrk(4096);
		chunks = 0;
	}

	size = ALIGN_SIZE(size);
	chunk = find_next_chunk(heap_start, chunks);
	chunks++;

	/* write chunk header */
	chunk_header = (nmheader_t *)chunk;
	chunk_header->size = size;

	/* write rest of heap header */
	new_header = (nmheader_t *)((char *)chunk + NHEADER_SIZE + size);
        new_header->size = *(size_t *)((char *)heap_end - (char *)new_header - NHEADER_SIZE);

	return (void *)((char *)chunk + NHEADER_SIZE);
}

/**
 * find_next_chunk - traverse the heap to find next free chunk
 * @ptr: starting point of heap
 * @chunks: number of chunks in heap
 *
 * Return: void * to next free chunk
 */

void *find_next_chunk(void *heap_start, size_t chunks)
{
	void *nptr;

	nptr = heap_start;
	while (chunks > 0)
	{
		nmheader_t *header = (nmheader_t *)nptr;
       		nptr = (void *)((char *)nptr + header->size + NHEADER_SIZE);
		chunks--;
	}
	return nptr;
}
