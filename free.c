#include "malloc.h"

/**
 * _free - frees a block of memory
 * @addr: the address of the memory
 *
 * Return: no return
 */

void _free(void *addr)
{
	mheader_t *entry;

	if(addr == NULL)
		return;
	entry = (mheader_t *)((char *)addr - HEADER_SIZE);
	entry->free = FREE;
	entry->in_use = 0;
}
