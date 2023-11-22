#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) return NULL;

    int count = 0;
    const char *tmp = str;
    while ((tmp = mx_strstr(tmp, sub))) {
        count++;
        tmp += mx_strlen(sub);
    }

    char *res = mx_strnew(mx_strlen(str) + count * (mx_strlen(replace) - mx_strlen(sub)));
    char *ptr = res;

    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(ptr, replace);
            ptr += mx_strlen(replace);
            str += mx_strlen(sub);
        } else {
            *ptr++ = *str++;
        }
    }

    return res;
}
