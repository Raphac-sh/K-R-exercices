#include <stdio.h>

int endString(char *s, char *t);

int main(void) {
    char s[] = "c'est drole \0";
    char t[] = "c'est drole \0";

    printf("%d", endString(s, t));
    return 0;
}

int endString(char *s, char *t) {
    char *pt = t;

    while(*s++);
    while(*t++);

    while(*--t == *--s) {
        if(t == pt) {
            break;
        }
    }

    if(t == pt && *t == *s && *s != '\0') return 1;
    else return 0;
}
