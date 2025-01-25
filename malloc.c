

/**
 * NOTES- DELETE LATER
 * add a struct member size_t in_use (smaller than size)
 * lets say chunk->size = 1024 but you wanna write 256
 * make a func to split that chunk!
 *
 * q: why have a previous pointer in the list?
 * coalesce : find first free. Is prev free? No? is next free? yes? consolidate.
 * increment. Is prev free? yes? consolidate. Increment. Are we free? yes. Is prev free? yes. Consolidate. Increment. Are we free? No. find next free.
 * if we want to write coalesce, keep prev. Otherwise, remove prev.
 *
 * malloc (malloc init)
 * coalesce on free
 *
 *
 */




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
	mheader_t *current, *new_header;

	if (!heap_start)
	{
		size_t increment = (size < PAGE_SIZE) ? PAGE_SIZE : 2 * size;
		heap_start = sbrk(0);
		if (sbrk(increment) == (void *)-1)
		{
			perror("sbrk failed");
			return (NULL);
		}
		heap_end = sbrk(0);
	}
	size = ALIGN_SIZE(size);

	new_header = NULL;
	while (new_header == NULL)
	{
		current = (mheader_t *)heap_start;
		if (current->next == NULL)
		{
			current->size = size;
			current->in_use = size;
			current->flag = ALLOCATED;
			current->next = make_header(((void *)(char *)current + current->size + HEADER_SIZE), *(size_t *)((char *)heap_end - (char *)current), NULL, INIT);

		}

		if (current->flag != FREE)
		{
			current = current->next;
			continue;
		}
		if (current->size > size)
		{
			if ((current->size - current->in_use)
				> size + HEADER_SIZE)
			{

			}

		}
	}
	return ((void *)(new_header + 1));
}


/**
 * make_header - makes a new header in memory
 * @addr: location of new header
 * @size: size of memory allocation
 * @next: pointer to next (value or NULL)
 * @flag: never FREE
 *
 * Return: pointer to alloc'd memory
 */

void *make_header(void *addr, size_t size, void *next, size_t flag)
{

}
