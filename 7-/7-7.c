#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

void search(FILE *fp, char *name, char *expr, int num, int except);

int main(int argc, char *argv[]) {
    int c, except = 0, num = 0;
    char expr[MAXLINE];
    FILE *fp;

    while(--argc > 0 && (*++argv)[0] == '-') {
        while((c = *++argv[0])) {
            switch(c) {
                case 'x':
                    except = 1;
                    break;
                case'n':
                    num = 1;
                    break;
                default:
                    printf("Found: forbidden option%c\n", c);
                    argc = 0;
                    break;
            }
        }
    }

    if(argc >= 1) strcpy(expr, *argv);
    else {
        printf("Usage : find -xn expression ...files\n");
        exit(1);
    }

    if(argc == 1) search(stdin, "", expr, num, except);
    else {
        while(--argc > 0) {
            if((fp = fopen(*++argv, "r")) == NULL) {
                printf("Error, couldn't open file %s", *argv);
                exit(1);
            } else {
                search(fp, *argv, expr, num, except);
            }
        }
    }

    return 0;
}

void search(FILE *fp, char *name, char *expr, int num, int except) {
    char line[MAXLINE];
    long int numline = 0;

    while(fgets(line, MAXLINE, fp) != NULL) {
        numline++;
        if((strstr(line, expr) != NULL) != except) {
            if(name) printf("%s, ", name);
            if(num) printf("%ld :", numline);
            printf("%s", line);
        }
    }
}


