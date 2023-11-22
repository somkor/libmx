#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr < 16) {
        char *hex = malloc(2);
        char hexdigits[] = "0123456789abcdef";
        hex[0] = hexdigits[nbr];
        hex[1] = '\0';
        return hex;
    } else {
        char *remainder = mx_nbr_to_hex(nbr / 16);
        char *hex = malloc(mx_strlen(remainder) + 2);
        int i = 0;
        while (remainder[i] != '\0') {
            hex[i] = remainder[i];
            i++;
        }
        hex[i] = "0123456789abcdef"[nbr % 16];
        hex[i + 1] = '\0';
        return hex;
    }
}
