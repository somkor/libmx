#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str)
        return -1;

    int res = 0;
    char delim[2] = {c, '\0'};

    while (*str == c)
        str++;

    const char *found = mx_strstr(str, delim);
    while (found) {
        res++;

        while (*found == c)
            found++;
        found = mx_strstr(found, delim);
    }

    if (*(str + mx_strlen(str) - 1) != c)
        res++;

    return res;
}
