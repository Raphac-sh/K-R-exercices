#include <stdio.h>

void strCat(char *s, char *t);

int main(void) {
    char s[] = "Hello, ";
    char t[] = "World!";

    strCat(s, t);
    printf("%s", s);
    return 0;
}

void strCat(char *s, char *t) {
    while(*++s);
    while((*s++ = *t++)); 
}
