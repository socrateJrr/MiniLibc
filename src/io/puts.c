#include <stdio.h>
#include <unistd.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <string.h>
int puts(const char *str)
{
    int nr = strlen(str);
    int apel = syscall(1, 1, str, nr);
    if (apel == -1)
        return -1;
    int apel2 = syscall(1, 1, "\n", 1);
    if (apel2 == -1)
        return -1;
    return 0;
}
