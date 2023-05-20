#ifndef H_VEC
#define H_VEC

#include <stdlib.h>
#include <string.h>
#include "bumper.h"

#define VEC_DEFINE(TYPE) typedef struct Vec_##TYPE { \
    Bumper *bumper; \
    TYPE *ptr; \
    size_t length; \
    size_t capacity; \
} Vec_##TYPE;

#define VEC_NEW(TYPE, BUMPER) (Vec_##TYPE){ .bumper = BUMPER, .ptr = NULL, .length = 0, .capacity = 0 }

#define VEC_PUSH(TYPE, VEC, ELEM) do { \
    if (++VEC.length <= VEC.capacity) {\
        VEC.ptr[VEC.length] = ELEM; \
        break; \
    } \
    TYPE *ptr = balloc(VEC.bumper, VEC.length); \
    memmove(ptr, VEC.ptr, VEC.length-1); \
    ptr[VEC.length-1] = ELEM; \
    VEC.ptr = ptr; \
    VEC.capacity++; \
} while(0)

#define VEC_POP(TYPE, VEC) VEC.ptr[--VEC.length]

#endif
