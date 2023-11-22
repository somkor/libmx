#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str)
        return NULL;

    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;

    const char *end = str + mx_strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
        end--;

    int len = end - str + 1;

    char *trim = mx_strnew(len);
    if (!trim)
        return NULL;

    for (int i = 0; i < len; i++)
        trim[i] = str[i];

    return trim;
}
