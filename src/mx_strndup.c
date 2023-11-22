#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t length = mx_strlen(s1);
    if (n < length) {
        length = n;
    }
    char *res = (char *)malloc(length + 1);
    if (res != NULL) {
        mx_strncpy(res, s1, length);
        res[length] = '\0';
    }
    return res;
}
