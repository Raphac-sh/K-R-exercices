#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char line1[100], line2[100];

    if(argc != 3) {
        fprintf(stderr, "Error, program needs two file names");
        exit(1);
    } else {
        if((fp1 = fopen(*++argv, "r")) == NULL || (fp2 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "Error: cannot open file");
            exit(1);
        } else {
            int i = 0;
            while(fgets(line1, 100, fp1) != NULL && fgets(line2, 100, fp2) != NULL) {
                i++;
                if(strcmp(line1, line2)) {
                    printf("%s%s%d", line1, line2, i);
                    return 0;
                }
            }
            fclose(fp1);
            fclose(fp2);
        }
    }

    return 0;
}
