#include "libmx.h"

char *mx_itoa(int number) {
    if (number == 0) {
        char *str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    int neg = 0;
    if (number < 0) {
        neg = 1;
        number = -number;
    }
    int length = 0;
    int temp = number;
    while (temp > 0) {
        temp /= 10;
        length++;
    }
    if (neg) length++;
    char *str = malloc(length + 1);
    str[length] = '\0';
    int i = length - 1;
    while (number > 0) {
        str[i--] = number % 10 + '0';
        number /= 10;
    }
    if (neg) str[0] = '-';
    return str;
}
