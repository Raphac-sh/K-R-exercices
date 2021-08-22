#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if(argc <= 1 || *argv[1] != '-') {
        printf("Usage: -m convertit en minuscules, -M convertit en majuscules");
        return -1;
    } else {
        int c;
        while((c = getchar()) != EOF) {
            switch(*(argv[1]+1)) {
                case 'm':
                    putchar(tolower(c));
                    break;

                case 'M': 
                    putchar(tolower(c));
                    break;

                default:
                    printf("unknown option");
                    return -1;
            }
        }
    }

    return 0;
}
