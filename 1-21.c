#include <stdio.h>

int main(void)
{
    int c;
    int spaces = 0;
    int tabSize = 4;


    int j;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            ++spaces;

            if(spaces % tabSize == 0) {
                putchar('\t');
            }
        }
        else {
            for(j = 0; j < (spaces % tabSize); ++j) {
                putchar(' ');
            }

            putchar(c);

            if(spaces != 0) spaces = 0;
        }
    }

    return 0;
}
