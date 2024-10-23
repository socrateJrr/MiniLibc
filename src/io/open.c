// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, mode_t mode)
{
	int fd = syscall(2, filename, flags, mode);
	if (fd < 0)
		return -1;
	return fd;
}
