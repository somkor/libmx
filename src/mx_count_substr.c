#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub)
        return -1;

    if (*sub == '\0')
        return 0;

    int count = 0;

    char *found = mx_strstr(str, sub);
    while (found) {
        count++;
        found = mx_strstr(found + 1, sub);
    }

    return count;
}
