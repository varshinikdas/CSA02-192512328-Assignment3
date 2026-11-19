#include <stdio.h>
#include <stdlib.h>

static long comparisons;

int linear_search(const int a[], int n, int key) {
    comparisons = 0;
    for (int i = 0; i < n; ++i) {
        ++comparisons;
        if (a[i] == key) return i;
    }
    return -1;
}

int binary_search(const int a[], int n, int key) {
    int low = 0, high = n - 1;
    comparisons = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        ++comparisons;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void) {
    int unsorted[] = {1190, 1021, 1460, 1103, 1533, 1222, 1402, 1048, 1305, 1377};
    int sorted[]   = {1021, 1048, 1103, 1190, 1222, 1305, 1377, 1402, 1460, 1533};
    int keys[] = {1021, 1305, 1533, 1400};
    int n = (int)(sizeof sorted / sizeof sorted[0]);
    puts("LIBRARY CATALOGUE SEARCH");
    for (int k = 0; k < 4; ++k) {
        int pos = linear_search(unsorted, n, keys[k]);
        printf("Linear key %d -> index %d, comparisons = %ld\n", keys[k], pos, comparisons);
        pos = binary_search(sorted, n, keys[k]);
        printf("Binary key %d -> index %d, comparisons = %ld\n", keys[k], pos, comparisons);
    }
    return 0;
}
