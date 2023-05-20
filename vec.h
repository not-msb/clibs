#ifndef H_VEC
#define H_VEC

#include <stdlib.h>
#include <string.h>
#include "bumper.h"

// Got this from https://stackoverflow.com/questions/9804371/syntax-and-sample-usage-of-generic-in-c11/17290414#17290414
#define typename(x) _Generic((x),                                                 \
            _Bool: "_Bool",                  unsigned char: "unsigned char",          \
             char: "char",                     signed char: "signed char",            \
        short int: "short int",         unsigned short int: "unsigned short int",     \
              int: "int",                     unsigned int: "unsigned int",           \
         long int: "long int",           unsigned long int: "unsigned long int",      \
    long long int: "long long int", unsigned long long int: "unsigned long long int", \
            float: "float",                         double: "double",                 \
      long double: "long double",                   char *: "pointer to char",        \
           void *: "pointer to void",                int *: "pointer to int",         \
          default: "other")

#define VEC_DEFINE(TYPE) typedef struct Vec_##TYPE { \
    Bumper *bumper; \
    TYPE *ptr; \
    size_t length; \
    size_t capacity; \
} Vec_##TYPE;

#define VEC_NEW(TYPE, BUMPER) (Vec_##TYPE){ .bumper = BUMPER, .ptr = NULL, .length = 0, .capacity = 0 }

#define VEC_PUSH(VEC, ELEM) do { \
    if (!strcmp(typename(VEC.ptr), typename(ELEM))) break; \
    if (++VEC.length <= VEC.capacity) { \
        VEC.ptr[VEC.length] = ELEM; \
        break; \
    } \
    size_t length = VEC.length*sizeof(ELEM); \
    typeof(*VEC.ptr) *ptr = balloc(VEC.bumper, length); \
    memmove(ptr, VEC.ptr, length-sizeof(ELEM)); \
    ptr[length-sizeof(ELEM)] = ELEM; \
    VEC.ptr = ptr; \
    VEC.capacity++; \
} while(0)

#define VEC_POP(VEC) VEC.ptr[--VEC.length]

#endif
