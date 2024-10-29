#include <time.h>
#include <unistd.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
unsigned int sleep(unsigned int seconds)
{
    struct timespec wish, tic;
    wish.tv_sec = seconds;
    tic.tv_nsec = 0;
    while (syscall(35, &wish, &tic) == -1)
    {
        if (errno != EINTR)
            return -1;
        tic = wish;
    }
    return 0;
}
int nanosleep(const struct timespec *t1, struct timespec *t2)
{
    int apel;
    apel = syscall(35, t1, t2);
    if (apel == -1 && errno == EINTR && t2)
        *t2 = *t1;
    return apel;
}