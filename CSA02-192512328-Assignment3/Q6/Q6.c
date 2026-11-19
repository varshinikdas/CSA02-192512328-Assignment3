#include <stdio.h>
#include <string.h>
#define MAX_NAMES 8
#define NAME_LEN 30

int compare_count, char_copies;
void insertion_sort_names(char names[][NAME_LEN], int n) {
    compare_count=char_copies=0;
    for(int i=1;i<n;++i) {
        char key[NAME_LEN]; strcpy(key,names[i]); char_copies+=(int)strlen(key)+1;
        int j=i-1;
        while(j>=0) {
            ++compare_count;
            if(strcmp(names[j],key)<=0) break;
            strcpy(names[j+1],names[j]); char_copies+=(int)strlen(names[j])+1;
            --j;
        }
        strcpy(names[j+1],key); char_copies+=(int)strlen(key)+1;
    }
}
int binary_search_name(char names[][NAME_LEN], int n, const char *key, int *checks) {
    int low=0,high=n-1; *checks=0;
    while(low<=high) {
        int mid=low+(high-low)/2; ++*checks;
        int c=strcmp(names[mid],key);
        if(c==0) return mid;
        if(c<0) low=mid+1; else high=mid-1;
    }
    return -1;
}
int main(void) {
    char names[MAX_NAMES][NAME_LEN]={"Varshini","Arun","Meena","Kavya","Bala","Divya","Meena","Zoya"};
    int n=MAX_NAMES, checks, pos;
    insertion_sort_names(names,n);
    puts("SORTED HOSTEL DIRECTORY");
    for(int i=0;i<n;++i) printf("%s\n",names[i]);
    printf("strcmp calls during insertion sort: %d\n",compare_count);
    printf("Character copies (including null terminators): %d\n",char_copies);
    pos=binary_search_name(names,n,"Meena",&checks);
    printf("Search Meena -> index %d, comparisons = %d\n",pos,checks);
    printf("Adjacent duplicate entries:");
    for(int i=1;i<n;++i) if(strcmp(names[i-1],names[i])==0) printf(" %s",names[i]);
    puts("");
    return 0;
}
