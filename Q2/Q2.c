#include <stdio.h>

typedef struct { long comparisons, moves; } Stats;

void bubble_sort(int a[], int n, Stats *s) {
    s->comparisons = s->moves = 0;
    for (int end = n - 1; end > 0; --end) {
        int swapped = 0;
        for (int i = 0; i < end; ++i) {
            ++s->comparisons;
            if (a[i] > a[i + 1]) {
                int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
                s->moves += 3; swapped = 1;
            }
        }
        if (!swapped) break;
    }
}
void selection_sort(int a[], int n, Stats *s) {
    s->comparisons = s->moves = 0;
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            ++s->comparisons;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t;
            s->moves += 3;
        }
    }
}
void insertion_sort(int a[], int n, Stats *s) {
    s->comparisons = s->moves = 0;
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            ++s->comparisons;
            if (a[j] <= key) break;
            a[j + 1] = a[j]; ++s->moves; --j;
        }
        a[j + 1] = key; ++s->moves;
    }
}
static void print_array(const int a[], int n) {
    for (int i=0;i<n;++i) printf("%d%s", a[i], i==n-1 ? "\n" : " ");
}
int main(void) {
    int input[4][6] = {
        {11, 18, 23, 31, 42, 57},
        {11, 18, 31, 23, 42, 57},
        {57, 42, 31, 23, 18, 11},
        {31, 11, 57, 18, 42, 23}
    };
    const char *labels[] = {"Sorted", "Nearly sorted", "Reverse sorted", "Random"};
    for (int r=0;r<4;++r) {
        int a[6],b[6],c[6]; Stats x,y,z;
        for(int i=0;i<6;++i) a[i]=b[i]=c[i]=input[r][i];
        bubble_sort(a,6,&x); selection_sort(b,6,&y); insertion_sort(c,6,&z);
        printf("%s input: ",labels[r]); print_array(input[r],6);
        printf("Bubble:    "); print_array(a,6);
        printf("  comparisons=%ld swaps/moves=%ld\n",x.comparisons,x.moves);
        printf("Selection: "); print_array(b,6);
        printf("  comparisons=%ld swaps/moves=%ld\n",y.comparisons,y.moves);
        printf("Insertion: "); print_array(c,6);
        printf("  comparisons=%ld shifts/moves=%ld\n",z.comparisons,z.moves);
    }
    return 0;
}
