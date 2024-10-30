// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int apel = syscall(4, path, buf);
	if (apel < 0)
	{
		errno = -apel;
		return -1;
	}

	return 0;
}
