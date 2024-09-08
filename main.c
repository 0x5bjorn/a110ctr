#include <stdint.h>

#include "arena.h"
#define ARENA_A110CTR_IMPL

int main()
{
    {
        Arena_t a = arena_init(256);

        int *x = (int *)arena_alloc(&a, 56);
        for (size_t i = 0; i < 56; i++)
            x[i] = i;

        char *y = (char *)arena_alloc(&a, 25);
        for (size_t i = 0; i < 25; i++)
            y[i] = i;

        size_t *z = (size_t *)arena_alloc(&a, 40);
        for (size_t i = 0; i < 40; i++)
            z[i] = i;

        arena_free(&a);
    }

    return 0;
}
