#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define abs(x) ((x < 0) ? -x : x)

int readline(char *s, int max);
void reverse(char *s);
void itoa(int n, char *s);
int atoi(char *s);
int chpos(char *s, char *t); 

int main(void) {
    char s[] = "hello, world";
    char t[] = "hell";

    printf("%d", chpos(s, t));
    return 0;
}

int readline(char *s, int max) {
    char c;
    char *t = s;

    while(--max > 0 && (*s = getchar()) && *s++ != '\n');

    *s++ = '\0';
    return s-t;
}

void reverse(char *s) {
    int c;
    char *t;

    for(t = s + strlen(s)-1; s < t; s++, t--) {
         c = *s;
         *s = *t;
         *t = c;
    }
}

void itoa(int n, char *s) {
    char *t = s;
    int sign = n;

    do {
        *s++ = abs((n % 10)) + '0';
    } while((n /= 10) != 0);

    if(sign < 0) *s++ = '-';

    *s = '\0';

    reverse(t);
}

int atoi(char *s) {
    int val = 0;
    int sign;

    while(isspace(*s)) s++;

    sign = (*s == '-') ? -1 : 1;

    if(*s == '-' || *s == '+') s++;
    while(isdigit(*s)) {
        val = 10 * val + (*s - '0');
        s++;
    }
    val = val * sign;

    return val;
}

int chpos(char *s, char *t) {
    char *k, *l, *m;
    l = s;
    while(*s) {
        k = s;
        m = k;
        while(*k == *t) {
            k++; 
            t++;
        }

        if(k > m && *t == '\0') {
            return s-l;
        }
        s++;
    }
    return -1;
}
