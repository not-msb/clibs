#include <stdio.h>
#include "bumper.h"
#include "string.h"

int main() {
    Bumper bumper = binit();

    String string1 = String_from(&bumper, "Sussy baka!");
    char *str1 = String_store(string1);
    printf("str1: %s\n", str1);

    String string2 = String_append(string1, " Lolllz!?!");
    char *str2 = String_store(string2);
    printf("str2: %s\n", str2);

    String string3 = String_prepend(string2, "Whaaat? ");
    char *str3 = String_store(string3);
    printf("str3: %s\n", str3);


    bfree(&bumper);
    return 0;
}
