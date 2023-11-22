#include "libmx.h"

char *mx_strdup(const char *str)
{
    if (str == NULL) return NULL;

    int length = mx_strlen(str);
    char *duplicate = mx_strnew(length);

    mx_strcpy(duplicate, str);
    
    return duplicate;
}
