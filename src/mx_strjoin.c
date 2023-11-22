#include "libmx.h"

char *mx_strjoin(const char *str1, const char *str2) {
    if (str1 == NULL && str2 == NULL)
        return NULL;

    if (!str1)
        return mx_strdup(str2);
    if (!str2)
        return mx_strdup(str1);

    int len1 = mx_strlen(str1);
    int len2 = mx_strlen(str2);
    char *str = mx_strnew(len1 + len2);
    if (!str)
        return NULL;

    mx_strcpy(str, str1);
    mx_strcpy(str + len1, str2);

    return str;
}
