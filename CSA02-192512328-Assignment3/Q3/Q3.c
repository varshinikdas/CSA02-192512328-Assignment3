#include <stdio.h>
#include <stddef.h>

long comparisons;
int merge_desc(const int a[], int na, const int b[], int nb, int out[]) {
    int i=0,j=0,k=0;
    comparisons=0;
    while (i<na && j<nb) {
        ++comparisons;
        if (a[i] >= b[j]) out[k++]=a[i++];
        else out[k++]=b[j++];
    }
    while(i<na) out[k++]=a[i++];
    while(j<nb) out[k++]=b[j++];
    return k;
}
int main(void) {
    int campusA[]={98,91,85,72}, campusB[]={95,91,80}, merged[7];
    int n=merge_desc(campusA,4,campusB,3,merged);
    printf("Merged merit list: ");
    for(int i=0;i<n;++i) printf("%d%s",merged[i],i==n-1?"\n":" ");
    printf("Merge comparisons: %ld\n",comparisons);
    {
        int empty[1], onlyB[]={90,80}, out[2];
        int count=merge_desc(empty,0,onlyB,2,out);
        printf("One empty list: ");
        for(int i=0;i<count;++i) printf("%d%s",out[i],i==count-1?"\n":" ");
    }
    return 0;
}
