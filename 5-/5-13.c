#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLONG 100

#define NDEFAULT 10

int readline(char *s, int max); 

int main(int argc, char *argv[]) {
    char *buffer;
    char *p;
    char *endBuffer;
    char line[MAXLONG];
    char *ptrlines[MAXLINES];

    int i, lastLine, firstLine, len, nlines;
    int n = NDEFAULT;

    if(argc == 2 && (*++argv)[0] == '-') {
        n = atoi(*(argv)+1);
    } else if(argc != 1) {
        printf("Error, usage : 'tail -n' where n is a number");
        return -1;
    }

    if(n < 1) return 0;
    if(n > MAXLINES) n = MAXLINES; 

    if((p = buffer = malloc(MAXLONG * MAXLINES)) == NULL) {
        printf("Error, cannot allocate buffer's memory");
        return -1;
    }
    endBuffer = buffer + MAXLONG*MAXLINES;
    lastLine = 0;
    nlines = 0;

    while((len = readline(line, MAXLONG)) > 0) {
        if(p + len > endBuffer) p = buffer;
        ptrlines[lastLine] = p;
        strcpy(p, line);

        if(++lastLine > MAXLINES) lastLine = 0;

        p += len + 1;
        nlines++;
    }

    if(n > nlines) n = nlines;
    
    firstLine = lastLine-n;
    if(firstLine < 0) firstLine += MAXLONG;
    for(int i = firstLine; n-- > 0; i = (i+1) % MAXLINES) {
        printf("%s", ptrlines[i]);
    }


    return 0;
}


int readline(char *s, int max) {
    char c;
    char *t = s;

    while(--max > 0 && (*s = getchar()) > 0 && *s++ != '\n');

    *s = '\0';
    return s-t;
}
