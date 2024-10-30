// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;
	int fd;
	if (flags & O_CREAT)
	{
		va_list valist;
		va_start(valist, flags);
		mode = va_arg(valist, mode_t);
		va_end(valist);
		fd = syscall(2, filename, flags, mode);
	} else {
		fd = syscall(2, filename, flags);
	}
	if (fd < 0)
	{
		errno = -fd;
		return -1;
	}
	return fd;
}
