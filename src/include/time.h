#ifndef __TIME_H__
#define __TIME_H__ 1

#ifdef __cplusplus
extern "C"
{
#endif

    struct timespec
    {
        long tv_sec;
        long tv_nsec;
    };

    unsigned int sleep(unsigned int seconds);
    int nanosleep(const struct timespec *t1, struct timespec *t2);

#ifdef __cplusplus
}
#endif

#endif
