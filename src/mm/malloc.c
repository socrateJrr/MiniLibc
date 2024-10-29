// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern struct mem_list mem_list_head; // = {NULL, 0, NULL, NULL};

void *malloc(size_t size)
{
	if (size == 0)
	{
		errno = EINVAL;
		return NULL;
	}
	struct mem_list *aux;
	while (aux)
	{
		if (aux->len >= size)
		{
			// aux->len = aux->len - size;
			void *ptr = aux->start;
			// aux->start = (char *)aux->start + size;
			return ptr;
		}
		aux = aux->next;
	}
	void *new = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	if (mem_list_add(new, size) == -1)
	{
		munmap(new, size);
		errno = ENOMEM;
		return NULL;
	}
	return new;
}
void *calloc(size_t nmemb, size_t size)
{

	return NULL;
}
void free(void *ptr)
{
	if (ptr == NULL)
		return;
	struct mem_list *new = mem_list_find(ptr);
	if (new)
	{
		munmap(ptr, new->len);
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{

	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{

	return NULL;
}
