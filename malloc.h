#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#define ALIGNMENT 8
#define HEADER_SIZE sizeof(mheader_t)
#define NHEADER_SIZE sizeof(nmheader_t)
#define ALIGN_SIZE(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

enum flags
{
	ALLOCATED,
	FREE
};

/**
 * mheader_t - header for _malloc
 * @size: the size of the block
 * @flag: 1 for free, 0 for allocated
 * @prev: pointer to the previous block
 * @next: pointer to the next block
 */

typedef struct mheader_s
{
	size_t size;
	uint64_t flag;
	void *prev;
	void *next;
} mheader_t;

/**
 * nmheader_t - header for the naive malloc
 * @size: the size of the block
 *
 */

typedef struct nmheader_s
{
	size_t size;
} nmheader_t;

void *naive_malloc(size_t size);
void *find_next_chunk(void *ptr, size_t chunk);
void *_malloc(size_t size);
void _free(void *ptr);

#endif
