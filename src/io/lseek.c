// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	int pos = syscall(8, fd, offset, whence);
	if (pos < 0)
	{
		errno = -pos;
		return -1;
	}
	return pos;
}
