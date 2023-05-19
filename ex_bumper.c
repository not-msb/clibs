#include <stdio.h>
#include "bumper.h"

int main() {
    Bumper bumper = binit();

    char *str = balloc(&bumper, sizeof(char)*2*8096);

    for (size_t i = 0; i<2*8096-1; i++) {
        str[i] = 'L';
    }
    str[2*8096-1] = '\0';

    printf("%s", str);

    bfree(&bumper);
    return 0;
}
