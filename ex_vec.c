#include <stdio.h>
#include "vec.h"

VEC_DEFINE(char);

int main() {
    Bumper bumper = binit();

    Vec_char v = VEC_NEW(char, &bumper);
    printf("Length before: %zu\n", v.length);
    printf("%s\n", v.ptr);

    VEC_PUSH(char, v, 'h');
    VEC_PUSH(char, v, 'e');
    VEC_PUSH(char, v, 'l');
    VEC_PUSH(char, v, 'l');
    VEC_PUSH(char, v, 'o');
    VEC_PUSH(char, v, '\0');
    printf("Length after:  %zu\n", v.length);
    printf("%s\n", v.ptr);

    for (size_t i = v.length; i>0; i--) {
        char c = VEC_POP(char, v);
        printf("popped: \'%c\'\n", c);
    }

    bfree(&bumper);
    return 0;
}
