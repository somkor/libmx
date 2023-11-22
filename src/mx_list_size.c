#include "libmx.h"

int mx_list_size(t_list *list) {
    int size = 0;
    t_list *node = list;

    while (node != NULL) {
        size++;
        node = node->next;
    }

    return size;
}
