#include <stdio.h>
#include <stdlib.h>

void printFil(FILE *fp, char *name) ;

int main(int argc, char *argv[]) {
    FILE *fp;

    if(argc == 1) {
        printFil(stdin, "");
    } else {
        while(--argc > 0) {
            if((fp = fopen(*argv, "r")) == NULL) {
                printf("Error, could not open file %s", *argv);
                exit(1);
            } else {
                printFil(fp, *argv);
                fclose(fp);
            }
        }
    }

    return 0;
}

void printFil(FILE *fp, char *name) {
    static int numpage = 1;
    char line[100];

    printf("%s, page %d\n", name, numpage);
    while((fgets(line, 100, fp)) != NULL) {
        fprintf(stdout, "%s\n", line);
    }

    numpage++;
    fprintf(stdout, "\f");
}
