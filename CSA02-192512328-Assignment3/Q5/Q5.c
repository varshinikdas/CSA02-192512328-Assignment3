#include <stdio.h>
#include <ctype.h>

int word_count(const char s[]) {
    int count=0, inside=0;
    for(int i=0;s[i]!='\0';++i) {
        if(s[i]==' ') inside=0;
        else if(!inside){inside=1;++count;}
    }
    return count;
}
int is_palindrome(const char s[]) {
    int left=0,right=0;
    while(s[right]!='\0') ++right;
    --right;
    while(left<right) {
        while(left<right && !isalpha((unsigned char)s[left])) ++left;
        while(left<right && !isalpha((unsigned char)s[right])) --right;
        if(tolower((unsigned char)s[left])!=tolower((unsigned char)s[right])) return 0;
        ++left;--right;
    }
    return 1;
}
void uppercase_copy(const char src[], char dst[], size_t cap) {
    size_t i=0;
    while(src[i]!='\0' && i+1<cap){dst[i]=(char)toupper((unsigned char)src[i]);++i;}
    dst[i]='\0';
}
void reverse_copy(const char src[], char dst[], size_t cap) {
    size_t n=0; while(src[n]!='\0') ++n;
    size_t i=0; while(i<n && i+1<cap){dst[i]=src[n-1-i];++i;}
    dst[i]='\0';
}
int main(void) {
    const char msg[]=" Meet at the library at 5 PM ";
    char upper[100], reversed[100];
    printf("Words: %d\n",word_count(msg));
    printf("Palindrome checks: %d %d\n",is_palindrome("Madam, I'm Adam"),is_palindrome("Hello"));
    uppercase_copy(msg,upper,sizeof upper); reverse_copy(msg,reversed,sizeof reversed);
    printf("Uppercase: %s\n",upper);
    printf("Reversed: %s\n",reversed);
    printf("Tab-separated word count (space-only rule): %d\n",word_count("one\ttwo"));
    return 0;
}
