// SPDX-License-Identifier: BSD-3-Clause
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/syscall.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long int apel = syscall(9, addr, length, prot, flags, fd, offset);
	if (apel < 0)
	{
		errno = -apel;
		return MAP_FAILED;
	}
	return (void *)apel;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long int new = syscall(25, old_address, old_size, new_size, flags);
	if (new < 0)
	{
		errno = -new;
		return MAP_FAILED;
	}
	return (void *)new;
}

int munmap(void *addr, size_t length)
{
	long int apel = syscall(11, addr, length);
	if (apel < 0)
	{
		errno = -apel;
		return -1;
	}
	return 0;
}
