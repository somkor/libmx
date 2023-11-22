#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = s;
    unsigned char uc = c;

    ptr += n;
    while (n--) {
        if (*--ptr == uc) {
            return (void *)ptr;
        }
    }

    return NULL;
}
