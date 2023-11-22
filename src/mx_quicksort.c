#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) return -1;
    int count = 0;
    if (left < right) {
        int pivot = mx_partition(arr, left, right, &count);
        mx_quicksort(arr, left, pivot - 1);
        mx_quicksort(arr, pivot + 1, right);
    }
    return count;
}
