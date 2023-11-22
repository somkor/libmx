#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d_ptr = dst;
    const unsigned char *s_ptr = src;
    unsigned char uc = c;

    while (n--) {
        *d_ptr = *s_ptr;
        if (*s_ptr == uc) {
            return d_ptr + 1;
        }
        d_ptr++;
        s_ptr++;
    }

    return NULL;
}
