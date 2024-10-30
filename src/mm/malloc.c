// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern struct mem_list mem_list_head;

void *malloc(size_t size)
{
	if (size == 0)
		return NULL;
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/*if (nmemb == 0 || size == 0)
		return NULL;
	size_t total = nmemb * size;
	void *ptr = mmap(NULL, total, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	memset(ptr, 0, total);
	return ptr;*/
}
void free(void *ptr)
{
	if (ptr == NULL)
		return;
	struct mem_list *block = mem_list_find(ptr);
	if (block != NULL)
	{
		mem_list_del(ptr);
		munmap(ptr, block->len);
	}
}

void *realloc(void *ptr, size_t size)
{
	/*if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(size);

	struct mem_list *block = mem_list_find(ptr);
	if (block == NULL)
		return NULL;

	size_t old_size = block->len;
	if (size <= old_size)
		return ptr;

	void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_ptr == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}

	memcpy(new_ptr, ptr, old_size);

	mem_list_del(ptr);
	munmap(ptr, old_size);

	if (mem_list_add(new_ptr, size) != 0)
	{
		munmap(new_ptr, size);
		return NULL;
	}
	return new_ptr;*/
	
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{

	return NULL;
}
