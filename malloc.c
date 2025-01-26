#include "malloc.h"

/**
 * _malloc - the naive implementation of malloc
 * @size: size of allocation
 *
 * Return: void * to allocated memory in heap
 */

void *_malloc(size_t size)
{
	static void *heap_start;
	static void *heap_end;
	size_t i;

	size = ALIGN_SIZE(size);
	i = GET_INCREMENT(size);

	if (!heap_start)
		return (heap_init(&heap_start, &heap_end, size, i));
	else
		return (find_block(&heap_start, &heap_end, size, i));
}


/**
 * make_header - makes a new header in memory
 * @addr: location of new header
 * @size: size of memory allocation
 * @next: pointer to next (value or NULL)
 * @free: status of memory
 *
 * Return: pointer to alloc'd memory
 */

void *make_header(void *addr, size_t size, void *next, size_t free)
{
	mheader_t *current = (mheader_t *)addr;

	current->size = size;
	current->in_use = size;
	current->next = next;
	current->free = free;

	return (current);
}

/**
 * heap_init - initializes the heap
 * @heap_start: the address of the start of the heap
 * @heap_end: the address at the end of the heap
 * @size: the size of the allocation
 * @i: the increment - 4096 unless less than size
 *
 * Return: no return;
 */

void *heap_init(void **heap_start, void **heap_end, size_t size, size_t i)
{
	void *end;

	*heap_start = ALIGN_UP(sbrk(0));
	if (sbrk(i) == (void *)-1)
	{
		perror("sbrk failed");
		return (NULL);
	}
	*heap_end = ALIGN_UP(sbrk(0));

	end = NEXT_HEADER(*heap_start);
	(void)make_header(*heap_start, size, end, NO);
	(void)make_header(end, GET_REMAIN(*heap_end, end), NULL, UNUSED);
	return ((void *)(((char *)*heap_start) + HEADER_SIZE));
}

/**
 * find_block - logic to find the next block
 * @heap_start: the address of the start of the heap
 * @heap_end: the address at the end of the heap
 * @size: the size of the allocation
 * @i: the increment - 4096 unless less than size
 *
 * Return: pointer to return to malloc
 */

void *find_block(void **heap_start, void **heap_end, size_t size, size_t i)
{
	mheader_t *new_header, *current = (mheader_t *)*heap_start;

	for (; new_header == NULL && current != NULL; current = current->next)
	{
		if (current->next == NULL)
		{
			if (current->size < size)
			{
				sbrk(i);
				*heap_end = sbrk(0);
			}
			current->size = size; current->in_use = size;
			current->free = NO;

			void *ptr = NEXT_HEADER(current);
			size_t remain = GET_REMAIN(*heap_end, current);
			current->next = make_header(ptr, remain, NULL, UNUSED);
			new_header = current; continue;
		}
		if (current->free != FREE)
			 continue;
		if ((current->size - current->in_use) > size + HEADER_SIZE)
		{
			void *snext,*next = current->next;
			size_t ssize;

			current->size = size; current->in_use = size;
			current->free = NO;
			snext = NEXT_HEADER(current);
			ssize = GET_REMAIN(snext, next);
			current->next = make_header(snext, ssize, next, FREE);
			new_header = current;
		}
		else
		{
			current->in_use = size; current->free = NO;
			new_header = current;
		}
	}
	return ((void *)(((char *)new_header) + HEADER_SIZE));
}
