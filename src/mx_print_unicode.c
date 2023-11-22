#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 0x80)
        mx_printchar(c);
    else {
        char byte = (c & 0x3F) | 0x80;
        if (c < 0x0800) {
            mx_printchar(((c >> 6) & 0x1F) | 0xC0);
            mx_printchar(byte);
        }
        else if (c < 0x010000) {
            mx_printchar(((c >> 12) & 0x0F) | 0xE0);
            mx_printchar(((c >> 6) & 0x3F) | 0x80);
            mx_printchar(byte);
        }
        else {
            mx_printchar(((c >> 18) & 0x07) | 0xF0);
            mx_printchar(((c >> 12) & 0x3F) | 0x80);
            mx_printchar(((c >> 6) & 0x3F) | 0x80);
            mx_printchar(byte);
        }
    }
}
