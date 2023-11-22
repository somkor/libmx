#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || !lineptr || !buf_size) return -2;

    char *buf = mx_strnew(buf_size);
    if (!buf) return -2;

    char *tmp = NULL;
    ssize_t read_bytes = 0;
    ssize_t total_bytes = 0;

    while ((read_bytes = read(fd, buf, buf_size)) > 0) {
        for (int i = 0; i < read_bytes; i++) {
            if (buf[i] == delim) {
                buf[i] = '\0';
                total_bytes += i;
                *lineptr = mx_strnew(total_bytes);
                mx_strcpy(*lineptr, tmp);
                free(tmp);
                free(buf);
                return total_bytes;
            }
        }
        char *new_tmp = mx_strnew(total_bytes + read_bytes);
        if (tmp) {
            mx_strcpy(new_tmp, tmp);
            free(tmp);
        }
        mx_strcpy(new_tmp + total_bytes, buf);
        tmp = new_tmp;
        total_bytes += read_bytes;
    }

    free(buf);

    if (read_bytes < 0) {
        free(tmp);
        return -2;
    }

    if (total_bytes > 0) {
        *lineptr = mx_strnew(total_bytes);
        mx_strcpy(*lineptr, tmp);
        free(tmp);
        return total_bytes;
    }

    return -1;
}
