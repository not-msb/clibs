#ifndef H_BUMPER
#define H_BUMPER

#include <stdlib.h>

#ifndef CHUNK
#define CHUNK 8096
#endif

typedef struct Bbuf {
    void *data;
    size_t length;
    size_t capacity;
} Bbuf;

Bbuf binit() {
    return (Bbuf){ .data = malloc(CHUNK), .length = 0, .capacity = CHUNK, };
}

void brealloc(Bbuf *bbuf, size_t size) {
    size_t length = bbuf->length + size;
    if (length <= bbuf->capacity) return;

    while (length > bbuf->capacity) {
        bbuf->capacity += CHUNK;
    }
    bbuf->data = realloc(bbuf->data, bbuf->capacity);
}

void *balloc(Bbuf *bbuf, size_t size) {
    brealloc(bbuf, size);

    void *ptr = bbuf->data + bbuf->length;
    bbuf->length += size;
    return ptr;
}

void bfree(Bbuf *bbuf) {
    free(bbuf->data);
    bbuf->data = NULL;
    bbuf->length = 0;
}

#endif
