// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int apel = syscall(76, path, length);
	if (apel < 0)
	{
		errno = -apel;
		return -1;
	}
	return 0;
}
