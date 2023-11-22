#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str)
        return NULL;

    char *trim = mx_strtrim(str);
    if (!trim)
        return NULL;

    int len = mx_strlen(trim);
    char *res = mx_strnew(len);
    if (!res) {
        free(trim);
        return NULL;
    }

    int j = 0;
    bool prev = false; 
    for (int i = 0; i < len; i++) {
        if (!mx_whitespace(trim[i])) {
            res[j++] = trim[i];
            prev = false;
        } else if (!prev) {
            res[j++] = ' ';
            prev = true;
        }
    }

    if (j > 0 && res[j-1] == ' ')
        res[j-1] = '\0';

    free(trim);
    return res;
}
