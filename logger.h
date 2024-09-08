#include <stdio.h>
#include <time.h>

#define LOG(msg, ...)                                              \
    {                                                              \
        current_time();                                            \
        printf("[%s:%d] (%s) ::: ", __FILE__, __LINE__, __func__); \
        printf((msg), ##__VA_ARGS__);                              \
        printf("\n");                                              \
    }

static void current_time()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}