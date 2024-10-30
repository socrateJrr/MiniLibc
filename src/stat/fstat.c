// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int apel = syscall(5, fd, st);
	if (apel < 0)
	{
		errno = -apel;
		return -1;
	}

	return 0;
}
