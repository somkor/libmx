#include "libmx.h"

int mx_strlen(const char *s) {
    int letter = 0;
    
    if (!s)
        return 0;
    while (s[letter])
        letter++;
    return letter;
}
