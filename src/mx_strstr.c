#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!*haystack || !*needle) return NULL;

    int lenn = mx_strlen(needle);
    int lenh = mx_strlen(haystack);

    for (int i = 0; i <= lenh - lenn; i++) {
        if (haystack[i] == needle[0]) {
            int j;
            for (j = 1; j < lenn; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == lenn)
                return (char *)haystack + i;
        }
    }

    return NULL;
}
