#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || cmp == NULL) return lst;

    int size = mx_list_size(lst);
    for (int i = 0; i < size - 1; i++) {
        t_list *current = lst;
        for (int j = 0; j < size - i - 1; j++) {
            if (cmp(current->data, current->next->data)) {
                void *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }

    return lst;
}
