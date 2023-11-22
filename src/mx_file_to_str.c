#include "libmx.h"

char *mx_file_to_str(const char *file) {

    if (file == NULL) return NULL;

    int fd = open(file, O_RDONLY);

    if (fd < 0) return NULL;

    int str_size = 0;
    char ch;

    while (read(fd, &ch, 1) > 0) str_size++;

    close(fd);

    if (str_size <= 0) return NULL;

    fd = open(file, O_RDONLY);

    if (fd < 0) return NULL;

    char *s = mx_strnew(str_size);

    read(fd, s, str_size);

    close(fd);

    return s;
}
