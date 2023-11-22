#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s)
        return NULL;

    int num = mx_count_words(s, c);

    char **arr = (char **)malloc((num + 1) * sizeof(char *));
    if (!arr)
        return NULL;

    int start = 0, end = 0;
    for (int i = 0; i < num; i++) {
        while (s[start] == c)
            start++;

        end = start;
        while (s[end] && s[end] != c)
            end++;

        arr[i] = mx_strnew(end - start);
        if (!arr[i]) {
            for (int j = 0; j < i; j++)
                free(arr[j]);
            free(arr);
            return NULL;
        }

        for (int j = 0; j < end - start; j++)
            arr[i][j] = s[start + j];

        start = end;
    }

    arr[num] = NULL;

    return arr;
}
