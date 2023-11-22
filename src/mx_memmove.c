#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    unsigned char *temp = malloc(len);

    if (temp != NULL) {
        mx_memcpy(temp, s, len);
        mx_memcpy(d, temp, len);
        free(temp);
    }

    return dst;
}
