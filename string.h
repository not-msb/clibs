#ifndef H_STRING
#define H_STRING

#include <stdlib.h>
#include <string.h>
#include "bumper.h"

typedef struct String {
    char *ptr;
    size_t length;
} String;

String String_new() {
    return (String){ .ptr = NULL, .length = 0 };
}

String String_from(char *str) {
    size_t length = strlen(str);
    return (String){ .ptr = str, .length = length };
}

String String_append(String string, Bumper *bumper, char *str) {
    size_t length = string.length+strlen(str);

    char *ptr = balloc(bumper, length);
    memmove(ptr, string.ptr, string.length);
    memmove(ptr+string.length, str, strlen(str));

    return (String){ .ptr = ptr, .length = length };
}

String String_prepend(String string, Bumper *bumper, char *str) {
    size_t length = string.length+strlen(str);

    char *ptr = balloc(bumper, length);
    memmove(ptr, str, strlen(str));
    memmove(ptr+strlen(str), string.ptr, string.length);

    return (String){ .ptr = ptr, .length = length };
}

char *String_store(String string, Bumper *bumper) {
    char *ptr = (char *) balloc(bumper, string.length+1);

    memmove(ptr, string.ptr, string.length);
    ptr[string.length] = '\0';

    return ptr;
}

#endif
