#include "libmx.h"

bool mx_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\f' || c == '\r';
}
