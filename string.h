#ifndef H_STRING
#define H_STRING

#include <stdlib.h>
#include <string.h>
#include "bumper.h"

typedef struct String {
    Bumper *bumper;
    char *ptr;
    size_t length;
} String;

String String_new(Bumper *bumper) {
    return (String){ .bumper = bumper, .ptr = NULL, .length = 0 };
}

String String_from(Bumper *bumper, char *str) {
    size_t length = strlen(str);
    return (String){ .bumper = bumper, .ptr = str, .length = length };
}

String String_append(String string, char *str) {
    size_t length = string.length+strlen(str);

    char *ptr = balloc(string.bumper, length);
    memmove(ptr, string.ptr, string.length);
    memmove(ptr+string.length, str, strlen(str));

    return (String){ .bumper = string.bumper, .ptr = ptr, .length = length };
}

String String_prepend(String string, char *str) {
    size_t length = string.length+strlen(str);

    char *ptr = balloc(string.bumper, length);
    memmove(ptr, str, strlen(str));
    memmove(ptr+strlen(str), string.ptr, string.length);

    return (String){ .bumper = string.bumper, .ptr = ptr, .length = length };
}

char *String_store(String string) {
    char *ptr = (char *) balloc(string.bumper, string.length+1);

    memmove(ptr, string.ptr, string.length);
    ptr[string.length] = '\0';

    return ptr;
}

#endif
