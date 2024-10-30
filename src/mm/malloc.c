// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/syscall.h>
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
	int sys = syscall(12, size);
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	int result = mem_list_add(ptr, size);
	if (result)
	{
		munmap(ptr, size);
		return NULL;
	}
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0)
		return NULL;
	size_t total = nmemb * size;
	void *ptr = mmap(NULL, total, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	memset(ptr, 0, total);
	int result = mem_list_add(ptr, size);
	if (result)
	{
		munmap(ptr, size);
		return NULL;
	}
	return ptr;
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
	// return ptr;
	if (size == 0)
		return NULL;
	void *new_ptr = mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_ptr == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	int result = mem_list_add(new_ptr, size);
	if (result)
	{
		munmap(new_ptr, size);
		return NULL;
	}
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return ptr;
}
