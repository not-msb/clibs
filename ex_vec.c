#include <stdio.h>
#include "vec.h"

VEC_DEFINE(char);

int main() {
    Bumper bumper = binit();

    Vec_char v = VEC_NEW(char, &bumper);
    printf("Length before: %zu\n", v.length);
    printf("%s\n", v.ptr);

    VEC_PUSH(v, 'h');
    VEC_PUSH(v, 'e');
    VEC_PUSH(v, 'l');
    VEC_PUSH(v, 'l');
    VEC_PUSH(v, 'o');
    VEC_PUSH(v, '\0');
    printf("Length after:  %zu\n", v.length);
    printf("%s\n", v.ptr);

    for (size_t i = v.length; i>0; i--) {
        char c = VEC_POP(v);
        printf("popped: \'%c\'\n", c);
    }

    bfree(&bumper);
    return 0;
}
