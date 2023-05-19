#ifndef H_BUMPER
#define H_BUMPER

#include <stdlib.h>

#ifndef CHUNK
#define CHUNK 8096
#endif

typedef struct Bumper {
    void *data;
    size_t length;
    size_t capacity;
} Bumper;

Bumper binit() {
    return (Bumper){ .data = malloc(CHUNK), .length = 0, .capacity = CHUNK, };
}

void brealloc(Bumper *bumper, size_t size) {
    size_t length = bumper->length + size;
    if (length <= bumper->capacity) return;

    while (length > bumper->capacity) {
        bumper->capacity += CHUNK;
    }
    bumper->data = realloc(bumper->data, bumper->capacity);
}

void *balloc(Bumper *bumper, size_t size) {
    brealloc(bumper, size);

    void *ptr = bumper->data + bumper->length;
    bumper->length += size;
    return ptr;
}

void bfree(Bumper *bumper) {
    free(bumper->data);
    bumper->data = NULL;
    bumper->length = 0;
}

#endif
