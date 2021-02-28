#include <stdio.h>

int strnCmp(char *s, char *t, int n);
int strnCat(char *s, char *t, int n);
void strnCpy(char *s, char *t, int n);

int main(void) {
    char s[] = "Hello, ";
    char t[] = "Hetyd!";

    printf("%d", strnCmp(s, t, 3));
    return 0;
}

int strnCmp(char *s, char *t, int n) {
    while(--n && *s++ == *t++);
    if(n == 0 && *s == *t) return 1;
    else return 0;

}

int strnCat(char *s, char *t, int n) {
    while(*++s);
    while(n-- && (*s++ = *t++));
    while(*s) *s++ = 0; 
}

void strnCpy(char *s, char *t, int n) {
    while(n-- && (*s++ = *t++));
    while(*s) *s++ = 0; 
}
