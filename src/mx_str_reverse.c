#include "libmx.h"

void mx_str_reverse(char *s) {
    if (s == NULL) return;
    int length = mx_strlen(s);
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}
