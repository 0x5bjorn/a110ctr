#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef struct Arena_t
{
    unsigned char *buf;
    size_t size;
    size_t offset;
} Arena_t;

Arena_t arena_init(size_t size);
void *arena_alloc(Arena_t *arena, size_t size);
void arena_free(Arena_t *arena);

// impl
#ifndef ARENA_A110CTR_IMPL

#define DEFAULT_ALIGNMENT (2 * sizeof(void *))
#define is_power_of_two(x) ((x != 0) && ((x & (x - 1)) == 0))

Arena_t arena_init(size_t size)
{
    void *buffer = malloc(size);
    return (Arena_t){.buf = buffer, .size = size, .offset = 0};
}

static uintptr_t align_forward(uintptr_t curr_offset_ptr, uintptr_t alignment)
{
    // TODO handle error case
    if (!is_power_of_two(alignment))
        return -1;

    uintptr_t new_offset_ptr = curr_offset_ptr;
    uintptr_t modulo = new_offset_ptr & (alignment - 1);

    if (modulo != 0)
        new_offset_ptr += alignment - modulo;

    return new_offset_ptr;
}

void *arena_alloc(Arena_t *arena, size_t size)
{
    uintptr_t curr_offset_ptr = (uintptr_t)arena->buf + (uintptr_t)arena->offset;
    uintptr_t new_offset_ptr = align_forward(curr_offset_ptr, (uintptr_t)DEFAULT_ALIGNMENT);
    size_t new_offset = new_offset_ptr - (uintptr_t)arena->buf;

    // TODO handle error case
    if (new_offset + size > arena->size)
        return NULL;

    void *ptr = &arena->buf[arena->offset];
    arena->offset = new_offset + size;

    // TODO memset 0 ????
    return ptr;
}

void arena_free(Arena_t *arena)
{
    arena->offset = 0;
}

#endif // !ARENA_A110CTR_IMPL