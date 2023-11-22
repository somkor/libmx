#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *d = dst;
    const char *ptr = src;
    for (size_t i = 0; i < n; i++) {
        d[i] = ptr[i];
    }
    return dst;
}
