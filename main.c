#include <stdio.h>
#include <stdint.h>

#include "arena.h"
#define ARENA_A110CTR_IMPL

int main()
{
    {
        Arena_t a = arena_init(256);
        int *x = (int *)arena_alloc(&a, 56);
        char *y = (char *)arena_alloc(&a, 25);
        size_t *z = (size_t *)arena_alloc(&a, 40);

        arena_free(&a);
    }

    return 0;
}
