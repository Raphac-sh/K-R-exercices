#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

#define NUMBER '0'

int lire_op(char s[]) {
    char c;
    float n;

    while(scanf("%c", &c) != EOF)
        if((s[0] = c) != ' ' || s[0] != '\t')
            break;
    
    if(c == EOF) return EOF;
    else if(!isdigit(c) && c != '.') return NUMBER;

    ungetc(c, stdin);
    scanf("%f", &n);
    sprintf(s, "%f", n);
    return NUMBER;
}
