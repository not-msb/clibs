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

#define VEC_PUSH(VEC, ELEM) do { \
    if (!__builtin_types_compatible_p(typeof(*VEC.ptr), typeof(ELEM))) break; \
    if (++VEC.length <= VEC.capacity) { \
        VEC.ptr[VEC.length] = ELEM; \
        break; \
    } \
    size_t length = VEC.length*sizeof(ELEM); \
    typeof(*VEC.ptr) *ptr = balloc(VEC.bumper, length); \
    memmove(ptr, VEC.ptr, length-sizeof(ELEM)); \
    ptr[VEC.length-1] = ELEM; \
    VEC.ptr = ptr; \
    VEC.capacity++; \
} while(0)

#define VEC_POP(VEC) VEC.ptr[--VEC.length]

#endif
