#include <stdio.h>
#include <string.h>

#define LGRMAX 1000
#define STCKMAX 1000


int readLines(char *ptrlig[], char *stock, int nlignes);
int readline(char *s, int max); 

int main(void) {
    char *lines[LGRMAX];
    char *stock;

    readLines(lines, stock, LGRMAX);
    printf("\n");
    int i = 0;
    while(lines[i]) {
        printf("%s", lines[i]);
        i++;
    }

    return 0;
}

int readLines(char *ptrlig[], char *stock, int lig) {
    int lgr, nlig;
    char *p = stock;
    char ligne[LGRMAX];
    char *max = p + STCKMAX; 

    nlig = 0;
    while((lgr = readline(ligne, LGRMAX)) > 0) {
        if(nlig >= lig || (p + lgr) > max) return -1;
        else {
            ligne[lgr-1] = '\0';
            strcpy(p, ligne);
            ptrlig[nlig++] = p;
            p += lgr;
        }
    }
}

int readline(char *s, int max) {
    char c;
    char *t = s;

    while(--max > 0 && (*s = getchar()) && *s++ != '\n');

    *s++ = '\0';
    return s-t;
}
