#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;
    while (*hex) {
        nbr *= 16;
        if (*hex >= '0' && *hex <= '9') {
            nbr += *hex - '0';
        } else if (*hex >= 'a' && *hex <= 'f') {
            nbr += *hex - 'a' + 10;
        } else if (*hex >= 'A' && *hex <= 'F') {
            nbr += *hex - 'A' + 10;
        }
        hex++;
    }
    return nbr;
}
