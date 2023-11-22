#include "libmx.h"

int mx_partition(char **arr, int left, int right, int *count) {
    int pivot = mx_strlen(arr[right]);
    int i = left;

    for (int j = left; j < right; j++) {
        if (mx_strlen(arr[j]) <= pivot) {
            if (i != j) {
                mx_swap_string(&arr[i], &arr[j]);
                int temp = *count;
                temp = temp + 1;
                *count = temp;
            }
            i++;
        }
    }
    if (i != right) {
        mx_swap_string(&arr[i], &arr[right]);
        int temp = *count;
        temp = temp + 1;
        *count = temp;
    }
    return i;
}
