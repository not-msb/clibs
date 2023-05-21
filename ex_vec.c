#include <stdio.h>
#include <stdint.h>
#include "vec.h"

VEC_DEFINE(int);

int main() {
    Bumper bumper = binit();

    Vec_int v1 = VEC_NEW(int, &bumper);
    printf("Length before: %zu\n", v1.length);
    printf("%ls\n", v1.ptr);

    VEC_PUSH(v1, 'h');
    VEC_PUSH(v1, 'e');
    VEC_PUSH(v1, 'l');
    VEC_PUSH(v1, 'l');
    VEC_PUSH(v1, 'o');
    VEC_PUSH(v1, '\0');
    printf("Length after:  %zu\n", v1.length);
    printf("%ls\n", v1.ptr);

    for (size_t i = v1.length; i>0; i--) {
        char c = VEC_POP(v1);
        printf("popped: \'%c\'\n", c);
    }

    printf("\n");

    Vec_int v2 = VEC_NEW(int, &bumper);
    printf("Length before: %zu\n", v2.length);

    VEC_PUSH(v2, 69);
    VEC_PUSH(v2, 420);
    VEC_PUSH(v2, 69420);
    printf("Length after:  %zu\n", v2.length);

    for (size_t i = v2.length; i>0; i--) {
        int c = VEC_POP(v2);
        printf("popped: \'%d\'\n", c);
    }

    bfree(&bumper);
    return 0;
}
