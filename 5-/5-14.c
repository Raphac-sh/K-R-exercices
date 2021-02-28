#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000

char *ptrlines[MAXLINES];

int readline(char *s, int max);
int readlines(char *ptrlines[], int nlines);
void writelines(char *ptrlines[], int nlines);

void fastSort(void *ptrlines[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);
int charcmp(char *s1, char *s2);

static int numbers = 0;
static int invert = 0;
static int maj = 0;
static int dict = 0;



int main(int argc, char *argv[]) {
    int nlines;
    if(argc > 1) {
        argc--;
        for(int i = 1; argc-- > 0; i++) {
           if(argv[i][0] != '-') continue;

           for(int j = 1; j < strlen(argv[i]); j++) {
               switch(argv[i][j]) {
                    case 'n':
                       numbers = 1;
                       break;
                    case 'i':
                       invert = 1;
                       break;

                    case 'm':
                        maj = 1;
                        break;
                    
                    case 'd':
                        dict = 1;
                        break;
               }
           }
        }

    }

    if((nlines = readlines(ptrlines, MAXLINES)) >= 0) {
        fastSort( (void **) ptrlines, 0, nlines-1, (int (*)(void *, void *)) (numbers ? numcmp : charcmp));

        writelines(ptrlines, nlines);
        return 0;
    } else {
        printf("Input too big to be sorted\n");
        return 1;
    }
}

void fastSort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void exchange(void *v[], int, int);

    if(left >= right) return;

    exchange(v, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++) {
        int equals = ((*comp)(v[i], v[left]));
        if(equals < -invert || equals == invert == 1) exchange(v, ++last, i);
    }

    exchange(v, left, last);
    fastSort(v, left, last-1, comp);
    fastSort(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if(v1 < v2) return -1;
    else if(v1 > v2) return 1;
    else return 0;
}

int charcmp(char *s1, char *s2) {
    char a, b;
    do {
        if(dict) {
            while(!isalnum(*s1) && *s1 != ' ' && *s1 != '\0') s1++;
            while(!isalnum(*s2) && *s2 != ' ' && *s2 != '\0') s2++;
        }

        a = maj ? tolower(*s1) : *s1;
        s1++;

        b = maj ? tolower(*s2) : *s2;
        s2++;

        if(a == b && a == '\0') return 0;
    } while(a == b);

    return a-b;
}

void exchange(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}

int readline(char *s, int max) {
    char c;
    char *t = s;

    while(--max > 0 && (*s = getchar()) > 0 && *s++ != '\n');

    *s = '\0';
    return s-t;
}

int readlines(char *ptrlines[], int lines) {
    int len, nlines;
    char *p, line[1000];

    nlines = 0;
    while((len = readline(line, 1000)) > 0) {
        if(nlines >= lines || (p = malloc(len)) == NULL) return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            ptrlines[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *ptrlines[], int lines) {
    for (int i = 0; i < lines; i++) printf("%s\n", ptrlines[i]);
}
