#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>

#define ALIGNMENT 8
#define HEADER_SIZE sizeof(mheader_t)
#define NHEADER_SIZE sizeof(nmheader_t)
#define ALIGN_SIZE(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))
#define ALIGN_UP(addr) ((void *)(((uintptr_t)(addr) + ALIGNMENT - 1) & ~(ALIGNMENT - 1)))
#define PAGE_SIZE 4096
#define GET_INCREMENT(size) ((((size) + PAGE_SIZE - 1) / PAGE_SIZE) * PAGE_SIZE)
#define GET_REMAIN(heap_end, current) \
	((char *)(heap_end) - (char *)(current))
#define NEXT_HEADER(current) \
	((void *)((char *)((mheader_t *)(current)) + ((mheader_t *)(current))->size + HEADER_SIZE))
/**
 * enum flags - sets to either allocated or free
 * @ALLOCATED: in use memory
 * @FREE: free'd memory
 *
 * This enum is used to flag memory as free or in use
 */

enum free
{
	NO,
	FREE,
	UNUSED
};


/**
 * struct mheader_s - header for _malloc
 * @size: the size of the block
 * @flag: 1 for free, 0 for allocated
 * @prev: pointer to the previous block
 * @next: pointer to the next block
 */

typedef struct mheader_s
{
	size_t size;
	size_t in_use;
	uint64_t free;
	void *next;
} mheader_t;

/**
 * struct nmheader_s - header for the naive malloc
 * @size: the size of the block
 *
 */

typedef struct nmheader_s
{
	size_t size;
} nmheader_t;

void *naive_malloc(size_t size);
void *find_next_chunk(void *, size_t);

void *_malloc(size_t size);
void *make_header(void *addr, size_t size, void *next, size_t free);
void *heap_init(void **heap_start, void **heap_end, size_t size, size_t i);
void *find_block(void **heap_start, void **heap_end, size_t size, size_t i);

void _free(void *addr);

void _write_size(size_t size);
#endif
