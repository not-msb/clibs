#include <stdio.h>
#include "bumper.h"
#include "string.h"

int main() {
    Bumper bumper = binit();

    String string1 = String_from("Sussy baka!");
    char *str1 = String_store(string1, &bumper);
    String string2 = String_append(string1, &bumper, " Lolllz!?!");
    char *str2 = String_store(string2, &bumper);
    String string3 = String_prepend(string2, &bumper, "Whaaat? ");
    char *str3 = String_store(string3, &bumper);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    bfree(&bumper);
    return 0;
}
