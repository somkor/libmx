#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL) return;
    t_list *node = *head;
    if (node->next == NULL) {
        free(node);
        *head = NULL;
    } else {
        t_list *previous_node;
        while (node->next != NULL) {
            previous_node = node;
            node = node->next;
        }
        free(node);
        previous_node->next = NULL;
    }
}
